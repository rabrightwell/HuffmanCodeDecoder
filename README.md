# HuffmanCodeDecoder

This program takes an inorder and preorder traversal of a tree to reconstruct a tree that is then used to decode a Huffman code.

PROJECT DETAILS:

The program will:

Compute the Huffman code tree from the two traversals.
Decode the text, writing the output to standard output (cout).

The format of the inorder and preorder traversals will be integer values separated by whitespace. The leaves of the tree will be values < 128, representing the ASCII value of the letter. The internal nodes of the tree will be values 128 and greater.

Requirements:

You must use good object-based organization, i.e. use classes in an appropriate way.
You are allowed to use any data structure in the standard library that has been coded on either a lab or project: vector, list, stack, queue.
You must use g++ -Wall -std=c++11 to compile
You must do your own work; you must not share code.

Examples
========
An example run:

./decode inorder0.txt preorder0.txt encoded0.txt

inorder0.txt:
66 129 76 128 77 130 65

preorder0.txt:
130 129 66 128 76 77 65

encoded0.txt:
101010010111

Output:
ALABAMA

Another example run:

./decode inorder1.txt preorder1.txt encoded1.txt

inorder1.txt:
10 128 33 134 121 133 117 138 114 135 106 131 71 143 100 140 32 145 101 141 89 130 108 137 99 144 111 142 116 139 120 129 98 136 104 132 46

preorder1.txt:
145 143 138 134 128 10 33 133 121 117 135 114 131 106 71 140 100 32 144 141 101 137 130 89 108 99 142 111 139 116 136 129 120 98 132 104 46 

encoded1.txt:
10100110000110110101001011110010100010011111011111010001111101001 11100111001110111100010001010010111110101010001011111100000001111
101100100110011011011110100001

Output:
You decoded the text correctly.
Good job!
