# msh

A small Unix shell written in C. It reads a line, splits it into tokens, and either runs a built-in or forks and `exec`s the program.

Written to learn how shells work. It follows the blog series [creating a terminal shell](https://www.kartikanand.com).

## Build and run

Requires `gcc` and `make`.

```sh
make
./bin/msh
```

```
welcome to msh - the modern shell v0.1
msh >> ls -l
```

Exit with `Ctrl-D`. `make clean` removes the `bin/` and `lib/` build directories.

## What it supports

- Running any program on your `PATH` with arguments (`fork` + `execvp` + `waitpid`)
- The `cd` built-in

Input is split on single spaces, up to 1024 tokens per line. It does not yet support quoting, pipes, redirection or background jobs.

## Layout

- `src/main.c`: the read-eval loop
- `src/shell.c`, `include/shell.h`: line reading, tokenizing and command execution
- `src/builtins.c`, `include/builtins.h`: built-in commands

## License

MIT. See [LICENSE](LICENSE).
