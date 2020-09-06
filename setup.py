#!/usr/bin/env python3

# BSD 2-Clause License
#
# Copyright (c) 2020, Hearot
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

import re
from distutils.core import Extension, setup

CLASSIFIERS = [
    "Development Status :: 5 - Production/Stable",
    "Intended Audience :: Developers",
    "Intended Audience :: Education",
    "Intended Audience :: Science/Research",
    "License :: OSI Approved :: BSD License",
    "Natural Language :: English",
    "Operating System :: OS Independent",
    "Programming Language :: C",
    "Programming Language :: Python",
    "Programming Language :: Python :: 3",
    "Programming Language :: Python :: 3 :: Only",
    "Programming Language :: Python :: 3.6",
    "Programming Language :: Python :: 3.7",
    "Programming Language :: Python :: 3.8",
    "Programming Language :: Python :: Implementation",
    "Programming Language :: Python :: Implementation :: CPython",
    "Topic :: Education",
    "Topic :: Scientific/Engineering",
    "Topic :: Scientific/Engineering :: Mathematics",
    "Topic :: Software Development :: Libraries",
    "Topic :: Software Development :: Libraries :: Python Modules",
]
KEYWORDS = "c calculation computation extension primecount primes"
GITHUB_REPOSITORY = "https://github.com/hearot/primecount/blob/v%s/"
LICENSE = "BSD2"
PACKAGE_NAME = "primecount"
SOURCE_FILE = "primecount.c"

primecount_module = Extension(
    "primecount", libraries=["primecount"], sources=[SOURCE_FILE],
)

with open("primecount.c", encoding="utf-8") as f:
    content = f.read()
    author = re.findall(r"PRIMECOUNT_PACKAGE_AUTHOR \"(.+)\"", content)[0]
    author_email = re.findall(
        r"PRIMECOUNT_PACKAGE_AUTHOR_EMAIL \"(.+)\"", content
    )[0]
    description = re.findall(
        r"PRIMECOUNT_PACKAGE_DESCRIPTION \"(.+)\"", content
    )[0]
    url = re.findall(r"PRIMECOUNT_PACKAGE_URL \"(.+)\"", content)[0]
    version = re.findall(r"PRIMECOUNT_PACKAGE_VERSION \"(.+)\"", content)[0]

with open("README.md", encoding="utf-8") as f:
    long_description = f.read().replace("./", GITHUB_REPOSITORY % version)


setup(
    author=author,
    author_email=author_email,
    classifiers=CLASSIFIERS,
    description=description,
    ext_modules=[primecount_module],
    keywords=KEYWORDS,
    license="BSD2",
    long_description=long_description,
    long_description_content_type="text/markdown",
    name=PACKAGE_NAME,
    project_urls={
        "Tracker": "https://github.com/hearot/primecount/issues",
        "Source": "https://github.com/hearot/primecount",
    },
    python_requires=">=3.6.*",
    url=url,
    version=version,
)
