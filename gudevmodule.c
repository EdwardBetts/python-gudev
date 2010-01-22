/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * gudevmodule.
 * Copyright (C) John Stowers 2008 <john.stowers@gmail.com>
 * 
 * osm-gps-map.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * osm-gps-map.c is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <pygobject.h>

void pygudev_register_classes(PyObject *d);
extern PyMethodDef pygudev_functions[];

DL_EXPORT(void)
initgudev(void)
{
	PyObject *m, *d;

	init_pygobject();

	m = Py_InitModule("gudev", pygudev_functions);
	d = PyModule_GetDict(m);

	pygudev_register_classes(d);
	pygudev_add_constants(m, "G_UDEV_");

	if (PyErr_Occurred()) {
		Py_FatalError("can't initialize module gudev");
	}
}
