# INCS Lab Programs

This repository contains the lab programs for the Information and Network Security (INCS) subject. The programs include implementations using Lex, Yacc, and C language. These are the practical exercises covered during the Flex Lab sessions.

## Contents

- **Lex Programs**: Programs written in Lex for lexical analysis.
- **Yacc Programs**: Programs that use Yacc for parsing, along with Lex for lexical analysis.
- **C Programs**: Various C programs related to INCS concepts.

## Directory Structure

The repository is organized as follows:

/lex/
lex_program1.l
lex_program2.l
…
/yacc/
yacc_program1.y
yacc_program2.y
…
/c/
program1.c
program2.c
…

Each directory contains the respective source files:

- **/lex/**: Contains Lex source files (.l).
- **/yacc/**: Contains Yacc source files (.y) and associated Lex files.
- **/c/**: Contains C programs.

## How to Compile and Run

### Lex Programs

1. Navigate to the `lex/` directory:

    ```bash
    cd lex
    ```

2. Compile the Lex program:

    ```bash
    lex lex_program1.l
    gcc lex.yy.c -o lex_program1
    ```

3. Run the Lex program:

    ```bash
    ./lex_program1
    ```

### Yacc Programs

1. Navigate to the `yacc/` directory:

    ```bash
    cd yacc
    ```

2. Compile the Yacc program along with its Lex file:

    ```bash
    yacc -d yacc_program1.y
    lex lex_file.l
    gcc y.tab.c lex.yy.c -o yacc_program1
    ```

3. Run the Yacc program:

    ```bash
    ./yacc_program1
    ```

### C Programs

1. Navigate to the `c/` directory:

    ```bash
    cd c
    ```

2. Compile the C program:

    ```bash
    gcc program1.c -o program1
    ```

3. Run the C program:

    ```bash
    ./program1
    ```

## Requirements

- **Lex**: A tool for generating lexical analyzers.
- **Yacc**: A tool for generating parsers.
- **GCC**: A compiler for C language.

Make sure these tools are installed on your system to compile and run the programs.

## Contributing

Contributions to this repository are welcome. Feel free to fork this repository, make changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
