/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * tampil.c
 * Copyright (C) adi sucipto 2011 <acepby@tajdidlinux.org>
 * 
 * tampil is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * tampil is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include "tampil.h" 
#include <string.h>

char* lsb(char *buffer)
{
	FILE *fp;
	char result[255];
	char *release;
	fp=popen(buffer,"r");
	fread(result,1,sizeof(result),fp);
	pclose(fp);
	//result=scanf("%s",result);
	release=strdup(result);
	return release;
}
	