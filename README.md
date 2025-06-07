# c-test

- In the VSCode window, you can open the terminal and interact with Bash by pressing `Ctrl+J`.
- Enter `make clean` to clean the project, and enter `make` to compile the project.
- To see the execution result, run the compiled executable `c-test` in the `bin/` directory.
- To format the source code, run the following command:

```bash
$(pwd)/Astyle/bin/astyle.exe --options=$(pwd)/_astylerc -I -R ./*.c,*.cpp,*.h --exclude=AStyle --formatted
```

- Convert Windows line endings (CRLF) to Unix/Linux line endings (LF):

```bash
find . -type f -exec dos2unix {} \;
```
