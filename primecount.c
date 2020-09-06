/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2020, Hearot
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <primecount.h>

#define PRIMECOUNT_PACKAGE_AUTHOR "Hearot"
#define PRIMECOUNT_PACKAGE_AUTHOR_EMAIL "gabriel@hearot.it"
#define PRIMECOUNT_PACKAGE_DESCRIPTION "A Python wrapper for primecount."
#define PRIMECOUNT_PACKAGE_COPYRIGHT \
  "Copyright (C) 2020 Hearot <https://github.com/hearot>"
#define PRIMECOUNT_PACKAGE_LICENSE "BSD 2-Clause License"
#define PRIMECOUNT_PACKAGE_NAME "primecount"
#define PRIMECOUNT_PACKAGE_URL "https://github.com/hearot/primecount"
#define PRIMECOUNT_PACKAGE_VERSION "1.0.0"

#define PRIMECOUNT_DOCSTRING_NTH_PRIME          \
  "nth_prime(n: int) -> int\n\n"                \
  "Find the nth prime.\n\n"                     \
  "Args:\n"                                     \
  "    n (int): The position of the prime.\n\n" \
  "Returns:\n"                                  \
  "    int: The nth-prime."

PyObject* nth_prime(PyObject* self, PyObject* args) {
  unsigned long long n;

  if (!PyArg_ParseTuple(args, "K", &n)) return NULL;

  return PyLong_FromLongLong(primecount_nth_prime(n));
}

#define PRIMECOUNT_DOCSTRING_PHI                                            \
  "phi(x: int, a: int) -> int\n\n"                                          \
  "Count the numbers <= x that are not divisible by any of the first a "    \
  "primes.\n\n"                                                             \
  "Args:\n"                                                                 \
  "    x (int): The upper limit x.\n"                                       \
  "    a (int): The number of primes which shall be tested.\n\n"            \
  "Returns:\n"                                                              \
  "    int: How many numbers less than or equal to x are not divisible by " \
  "any of the first a primes."

PyObject* phi(PyObject* self, PyObject* args) {
  unsigned long long x;
  unsigned long long a;

  if (!PyArg_ParseTuple(args, "KK", &x, &a)) return NULL;

  return PyLong_FromLongLong(primecount_phi(x, a));
}

#define PRIMECOUNT_DOCSTRING_PI          \
  "pi(x: int) -> int\n\n"                \
  "Count the number of primes <= x.\n\n" \
  "Args:\n"                              \
  "    x (int): The upper limit x.\n\n"  \
  "Returns:\n"                           \
  "    int: How many numbers less than or equal to x are primes."

PyObject* pi(PyObject* self, PyObject* args) {
  unsigned long long x;

  if (!PyArg_ParseTuple(args, "K", &x)) return NULL;

  return PyLong_FromLongLong(primecount_pi(x));
}

static PyMethodDef primecount_methods[] = {
    {"nth_prime", (PyCFunction)nth_prime, METH_VARARGS,
     PRIMECOUNT_DOCSTRING_NTH_PRIME},
    {"phi", (PyCFunction)phi, METH_VARARGS, PRIMECOUNT_DOCSTRING_PHI "primes"},
    {"pi", (PyCFunction)pi, METH_VARARGS, PRIMECOUNT_DOCSTRING_PI},
    {NULL, NULL, 0, NULL}};

static PyModuleDef primecount_module = {PyModuleDef_HEAD_INIT, "primecount",
                                        PRIMECOUNT_PACKAGE_DESCRIPTION, 0,
                                        primecount_methods};

PyMODINIT_FUNC PyInit_primecount() {
  PyObject* primecount = PyModule_Create(&primecount_module);

  PyObject* __author__ = Py_BuildValue("s", PRIMECOUNT_PACKAGE_AUTHOR);
  PyObject* __author_email__ =
      Py_BuildValue("s", PRIMECOUNT_PACKAGE_AUTHOR_EMAIL);
  PyObject* __copyright__ = Py_BuildValue("s", PRIMECOUNT_PACKAGE_COPYRIGHT);
  PyObject* __license__ = Py_BuildValue("s", PRIMECOUNT_PACKAGE_LICENSE);
  PyObject* __package__ = Py_BuildValue("s", PRIMECOUNT_PACKAGE_NAME);
  PyObject* __url__ = Py_BuildValue("s", PRIMECOUNT_PACKAGE_URL);
  PyObject* __version__ = Py_BuildValue("s", PRIMECOUNT_PACKAGE_VERSION);

  PyObject_SetAttrString(primecount, "__author__", __author__);
  PyObject_SetAttrString(primecount, "__author_email__", __author_email__);
  PyObject_SetAttrString(primecount, "__copyright__", __copyright__);
  PyObject_SetAttrString(primecount, "__license__", __license__);
  PyObject_SetAttrString(primecount, "__package__", __package__);
  PyObject_SetAttrString(primecount, "__url__", __url__);
  PyObject_SetAttrString(primecount, "__version__", __version__);

  Py_DECREF(__author__);
  Py_DECREF(__author_email__);
  Py_DECREF(__copyright__);
  Py_DECREF(__license__);
  Py_DECREF(__package__);
  Py_DECREF(__url__);
  Py_DECREF(__version__);

  return primecount;
}
