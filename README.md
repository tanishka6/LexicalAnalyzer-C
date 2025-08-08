# LexicalAnalyzer-C
*COMPANY*: CODTECH IT SOLUTIONS;
*NAME*: TANISHKA GARIYA;
*INTERN ID*: CT04DH2132;
*DOMAIN*: C PROGRAMMING;
*DURATION*: 4 WEEKS;
*MENTOR*: NEELA SANTHOSH KUMAR

🔍 Project Title: Lexical Analyzer in C (Keyword, Identifier & Operator Detection)
💻 Platform Used: Dev C++
🎓 Learning Resources: YouTube, GeeksforGeeks, ChatGPT
🧾 Description:
This C program implements a basic Lexical Analyzer — a key component of a compiler — to identify and classify different tokens from a source code file. It reads the contents of a file (file.txt) and detects:

Keywords

Identifiers

Operators

It ignores constants and separators for simplicity.

🔍 Key Functionalities:
✅ Keyword Detection:
Matches words against a predefined list of 32 C language reserved keywords.

Uses strcmp() to compare extracted tokens.

✅ Identifier Detection:
Any word that is not a keyword or constant (and starts with a letter or underscore) is considered an identifier.

✅ Operator Detection:
Recognizes common single-character operators such as +, -, *, /, =, <, >, &, |, etc.

✅ Constants Ignored:
Numeric constants (pure digits) are identified but not printed in the output to focus only on lexical classification of keywords and identifiers.

✅ File Handling:
Reads content from a file (file.txt) using standard file I/O (fopen, fgetc, fclose).

📘 Example Input (file.txt):
int a = 10;
if (a > 5) {
    return a;
}

📤 Lexical Analyzer Output:
int: Keyword
a: Identifier
=: Operator
if: Keyword
a: Identifier
>: Operator
return: Keyword
a: Identifier


✅ Concepts Practiced:
Compiler design fundamentals (Lexical Analysis)

Token classification (Keywords, Identifiers, Operators)

File handling and stream processing

Use of character-level reading and string buffering

C string manipulation and classification functions (isalnum, isdigit, etc.)

💡 Learning Outcome:
This project introduced me to the first phase of compilation — lexical analysis — and strengthened my understanding of how compilers tokenize source code. It also gave hands-on experience with file reading, token parsing, and the structure of programming languages at the lexical level.

📚 Acknowledgments:
Developed with reference to:

YouTube tutorials (for compiler theory and lexical analysis examples)

GeeksforGeeks (for token types and implementation help)

ChatGPT (for explaining logic, debugging, and enhancements)
