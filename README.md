# 📊 **Word Frequency Counter**
![Header](/assets/header.png)

This is a simple CLI program in C that reads text from a file, counts the frequency of each word, and then displays the words along with their frequencies in descending order. It also removes punctuation marks and converts all letters to lowercase to ensure accurate counting.

## **Code Explanation**

### Libraries
- The program includes standard C libraries such as `stdio.h`, `string.h`, `ctype.h`, and `stdlib.h` for input/output, string manipulation, character handling, and memory allocation respectively.

### Function Prototypes
- Prototypes of all functions used in the program are declared. These include functions for converting text to lowercase, stripping punctuations, reading a file, replacing newlines, and sorting the dictionary.

### Macros and Structures
- Macros are defined for maximum entries and maximum word length.
- A structure `Dict` is defined to store words and their counts.

### Main Function
- The main function begins program execution.
- It reads text from a file, replaces newlines with spaces, converts text to lowercase, and strips off punctuations.
- It initializes a dictionary to store words and their counts.
- It tokenizes the text and counts the occurrences of each word, updating the dictionary accordingly.
- Finally, it sorts the dictionary in descending order of word counts and prints the words along with their frequencies.

### Functions
- Functions are defined for converting text to lowercase, stripping punctuations, reading a file, replacing newlines, and sorting the dictionary.
- `quickSort` and `partition` functions implement the quicksort algorithm to sort the dictionary based on word counts.

## Features

- Reads text from a file.
- Counts the frequency of each word.
- Removes punctuation marks.
- Converts all letters to lowercase.
- Displays words along with their frequencies in descending order.

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/word-frequency-counter.git
   ```

2. Compile the program:

   ```bash
   gcc word_frequency_counter.c -o word_frequency_counter
   ```

3. Run the program:

   ```bash
   ./word_frequency_counter
   ```

   Make sure to replace `"AI For Space Transportation.txt"` with the path to your text file.

## Example

Suppose you have a text file named `"sample.txt"` containing the following text:

```
This is a sample text file. This text file contains some words. Some words may repeat.
```

Running the program with this file would produce the following output:

```
words: 3
text: 2
file: 2
some: 2
contains: 1
may: 1
repeat: 1
sample: 1
this: 1
```

## Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
