# WC Tool Implementation in C

This is a custom implementation of the Unix `wc` (word count) utility in C. It provides functionality to count lines, words, and bytes in files or standard input.

## Features

- Count lines (`-l`)
- Count words (`-w`)
- Count bytes (`-c`)
- Count characters (`-m`)
- Process multiple files
- Read from standard input if no file is specified

## Usage

```
./wc [OPTION]... [FILE]...
```

If no FILE is specified, the program reads from standard input.

### Options

- `-l`: Print the newline count
- `-w`: Print the word count
- `-c`: Print the byte count
- `-m`: Print the character count

If no options are specified, the program defaults to printing line, word, and byte counts.

## Compilation

To compile the program, use a C compiler such as gcc:

```
gcc -o wc wc.c
```

## Examples

1. Count lines, words, and bytes in a file:
   ```
   ./wc example.txt
   ```

2. Count only words in a file:
   ```
   ./wc -w example.txt
   ```

3. Count lines and bytes in multiple files:
   ```
   ./wc -l -c file1.txt file2.txt
   ```

4. Read from standard input:
   ```
   echo "Hello, world!" | ./wc
   ```

## Implementation Details

This implementation closely mimics the behavior of the standard Unix `wc` command. It processes files sequentially and handles various edge cases, such as:

- Empty files
- Files with no newline at the end
- Multiple consecutive whitespace characters

The program uses efficient file I/O operations and minimizes memory usage by processing input character by character.

## Limitations

- The current implementation does not support all options available in the standard `wc` command.
- Unicode support is limited and may not accurately count characters in all cases when using the `-m` option.

## Contributing

Feel free to fork this project and submit pull requests for any improvements or additional features you'd like to see implemented.

## License

This project is open source and available under the [MIT License](LICENSE).
