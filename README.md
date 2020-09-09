# primecount
A Python wrapper for [primecount](https://github.com/kimwalisch/primecount).

### Documentation

This package follows the documentation provided by [the C API reference](https://github.com/kimwalisch/primecount), generating three methods: `primecount.nth_prime`, `primecount.pi` and `primecount.phi`.

### Installation

In the first place, you have to download [the source code of the library](https://github.com/kimwalisch/primecount) and build it. Make sure you have installed [cmake](https://cmake.org/), [git](https://git-scm.com/) and [make](https://www.gnu.org/software/make/). You might have to make use of `sudo` if `make install` ever fails.

```
git clone https://github.com/kimwalisch/primecount
cd primecount
cmake . -DBUILD_SHARED_LIBS=ON
make -j
make install
```

After having installed the library, it's time to install the Python wrapper by cloning this repository. Make sure you have installed [pip](https://pypi.org/project/pip/) and that `primecount` is reachable as a shared library using a compiler.

```
git clone https://github.com/hearot/primecount
cd primecount
pip install .
```

Instead of the last command, you can type `python setup.py install` as well.

### Commit messages

> See [Conventional Commits](https://www.conventionalcommits.org).

### Contributing

> See [CONTRIBUTING.md](./CONTRIBUTING.md).

### Versioning

> See [PEP 440](https://www.python.org/dev/peps/pep-0440/).

### Copyright & License

- Copyright (C) 2020 [Hearot](https://github.com/hearot).
- Licensed under the terms of the [BSD 2-Clause License](./LICENSE).
