//
//  steam.cpp
//  Hello Steam
//
//  Created by Vinyl Darkscratch on 5/19/14.
//  Copyright (c) 2014 Nightwave Studios. All rights reserved.
//

#include <Python.h>

#include "steam/steam_api.h"
#include "steam/steam_gameserver.h"

#include <unistd.h>
#include <iostream>

static PyObject *steam_init(PyObject *self, PyObject *args);
static PyObject *steam_shutdown(PyObject *self, PyObject *args);
static PyObject *steam_get_name(PyObject *self, PyObject *args);
static PyObject *SteamInitError;

static PyMethodDef module_methods[] = {
    { "init", steam_init, METH_NOARGS, NULL },
    { "shutdown", steam_shutdown, METH_NOARGS, NULL },
    { "getName", steam_get_name, METH_NOARGS, NULL },
    { NULL, NULL, 0, NULL }
};

static PyObject *steam_init(PyObject *self, PyObject *args) {
	bool success = SteamAPI_Init();
	if (success) {
		Py_RETURN_NONE;
	}
	else {
		PyErr_SetString(SteamInitError, "Steam initialization failed!  Either Steam is not running or steam_appid.txt is not in your root folder.");
		Py_RETURN_NONE;
	};
};

static PyObject *steam_shutdown(PyObject *self, PyObject *args){
	SteamAPI_Shutdown();
	Py_RETURN_NONE;
}

static PyObject *steam_get_name(PyObject *self, PyObject *args){
	const char *playerName = SteamFriends()->GetPersonaName();
	return Py_BuildValue("s", playerName);
};

PyMODINIT_FUNC initPySteamAPI() {
	PyObject *m;

    m = Py_InitModule3("PySteamAPI", module_methods, "Simply initialize the Steam API.");

    if (m == NULL) return;

    SteamInitError = PyErr_NewException("Steam.InitError", NULL, NULL);
    Py_INCREF(SteamInitError);
    PyModule_AddObject(m, "error", SteamInitError);
}

