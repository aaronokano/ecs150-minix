/*
 * (c) copyright 1987 by the Vrije Universiteit, Amsterdam, The Netherlands.
 * See the copyright notice in the ACK home directory, in the file "Copyright".
 */
/* $Id: stb.c,v 1.1 2005/09/01 12:13:20 beng Exp $ */
/* library routine for copying structs */

__stb(n, f, t)
	register char *f, *t; register n;
{
	if (n > 0)
		do
			*t++ = *f++;
		while (--n);
}
