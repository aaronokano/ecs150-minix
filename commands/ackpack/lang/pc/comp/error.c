/* E R R O R   A N D   D I A G N O S T I C   R O U T I N E S */

/*	This file contains the (non-portable) error-message and diagnostic
	giving functions.  Be aware that they are called with a variable
	number of arguments!
*/

#include	"debug.h"
#include	"errout.h"

#include	<stdarg.h>
#include	<em_arith.h>
#include	<em_label.h>
#include	<em_code.h>
#include	<system.h>

#include	"prototypes.h"
#include	"f_info.h"
#include	"input.h"
#include	"main.h"

/* error classes */
#define	ERROR		1
#define	WARNING		2
#define	LEXERROR	3
#define	LEXWARNING	4
#define	CRASH		5
#define	FATAL		6
#ifdef DEBUG
#define VDEBUG		7
#endif

int err_occurred;

/*	There are three general error-message functions:
		lexerror()	lexical and pre-processor error messages
		error()		syntactic and pre-processor messagese
		node_error()	errors in nodes
	The difference lies in the place where the file name and line
	number come from.
	Lexical errors report from the global variables LineNumber and
	FileName, node errors get their information from the
	node, whereas other errors use the information in the token.
*/

static
void
_error(int class,struct node * node,const char * fmt,va_list ap)
{
	/*	_error attempts to limit the number of error messages
		for a given line to MAXERR_LINE.
	*/
	static unsigned int last_ln = 0;
	unsigned int ln = 0;
	static const char * last_fn = 0;
	static int e_seen = 0, w_seen = 0;
	register const char *remark = 0;

	/*	Since name and number are gathered from different places
		depending on the class, we first collect the relevant
		values and then decide what to print.
	*/
	/* preliminaries */
	switch( class )	{
		case ERROR:
		case LEXERROR:
		case CRASH:
		case FATAL:
			if( C_busy() ) C_ms_err();
			err_occurred = 1;
			break;
	}

	/* the remark */
	switch( class )	{
		case WARNING:
		case LEXWARNING:
			if (options['w']) return;
			remark = "(warning)";
			break;
		case CRASH:
			remark = "CRASH\007";
			break;
		case FATAL:
			remark = "fatal error --";
			break;
#ifdef DEBUG
		case VDEBUG:
			remark = "(debug)";
			break;
#endif /* DEBUG */
	}

	/* the place */
	switch( class )	{
		case ERROR:
		case WARNING:
			ln = node ? node->nd_lineno : dot.tk_lineno;
			break;
		case LEXWARNING:
		case LEXERROR:
		case CRASH:
		case FATAL:
#ifdef DEBUG
		case VDEBUG:
#endif /* DEBUG */
			ln = LineNumber;
			break;
	}

#ifdef DEBUG
	if( class != VDEBUG )	{
#endif
	if( FileName == last_fn && ln == last_ln )	{
		/* we've seen this place before */
		if( class != WARNING && class != LEXWARNING ) {
			e_seen++;
			if( e_seen == MAXERR_LINE ) fmt = "etc ...";
			else if( e_seen > MAXERR_LINE )
				/* and too often, I'd say ! */
				return;
		}
		else {
			w_seen++;
			if( w_seen == MAXERR_LINE ) fmt = "etc ...";
			else if( w_seen > MAXERR_LINE )
				return;
		}
	}
	else	{
		/* brand new place */
		last_ln = ln;
		last_fn = FileName;
		e_seen = w_seen = 0;
	}
#ifdef DEBUG
	}
#endif /* DEBUG */

	if( FileName ) fprintf(ERROUT, "\"%s\", line %u: ", FileName, ln);

	if( remark ) fprintf(ERROUT, "%s ", remark);

	vfprintf(ERROUT, fmt, ap);		/* contents of error */
	fprintf(ERROUT, "\n");
}

#ifdef DEBUG
/*VARARGS*/
void
debug(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(VDEBUG, NULLNODE, fmt, ap);
	}
	va_end(ap);
}
#endif /* DEBUG */

/*VARARGS*/
void
error(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(ERROR, NULLNODE, fmt, ap);
	}
	va_end(ap);
}

/*VARARGS*/
void
node_error(struct node *node, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(ERROR, node, fmt, ap);
	}
	va_end(ap);
}

/*VARARGS*/
void
warning(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(WARNING, NULLNODE, fmt, ap);
	}
	va_end(ap);
}

/*VARARGS*/
void
node_warning(struct node *node, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(WARNING, node, fmt, ap);
	}
	va_end(ap);
}

/*VARARGS*/
void
lexerror(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(LEXERROR, NULLNODE, fmt, ap);
	}
	va_end(ap);
}

/*VARARGS*/
void
lexwarning(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(LEXWARNING, NULLNODE, fmt, ap);
	}
	va_end(ap);
}

/*VARARGS*/
void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(FATAL, NULLNODE, fmt, ap);
	}
	va_end(ap);
	exit( 1 );
}

/*VARARGS*/
void
crash(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	{
		_error(CRASH, NULLNODE, fmt, ap);
	}
	va_end(ap);
#ifdef DEBUG
	abort( );
#else
	exit( 1 );
#endif
}
