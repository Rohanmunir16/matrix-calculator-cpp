Matrix Calculator in C++

An advanced console-based Matrix Calculator developed in C++ using Object-Oriented Programming (OOP) concepts.
The project supports multiple matrix operations including addition, subtraction, multiplication, transpose, determinant calculation, scalar multiplication, file handling, and operator overloading.

Features
Matrix Addition
Matrix Subtraction
Matrix Multiplication
Scalar Multiplication
Matrix Transpose
Determinant Calculation
Matrix Equality Check
Matrix File Save & Load
Dynamic Memory Allocation
Operator Overloading
Exception Handling
Square Matrix Support
Technologies Used
C++
OOP Concepts
File Handling
Dynamic Memory Management
Exception Handling
OOP Concepts Implemented
Concept	Usage
Classes & Objects	Matrix and SquareMatrix classes
Inheritance	SquareMatrix inherits Matrix
Constructors	Parameterized & Copy constructors
Destructor	Memory deallocation
Operator Overloading	+=, -=, *=
Encapsulation	Matrix operations inside classes
Exception Handling	Error handling using try-catch
Supported Operations
Operation	Description
Addition	A + B
Subtraction	A - B
Multiplication	A × B
Scalar Multiplication	Matrix × Scalar
Transpose	Matrix transpose
Determinant	Square matrix determinant
Inverse	Basic inverse implementation
Equality Check	Compare matrices
Save to File	Store matrices in text file
Load from File	Read matrices from file

Project Structure

matrix-calculator-cpp/
│
├── main.cpp
├── matrix_data.txt
└── README.md

Menu Options
1. Input Matrix A
2. Input Matrix B
3. Display Matrix A
4. Display Matrix B
5. Add Matrices
6. Subtract Matrices
7. Multiply Matrices
8. Scalar Multiplication
9. Check Equality
10. Transpose Matrix
11. Calculate Determinant
12. Calculate Inverse
13. Save Matrix A
14. Save Matrix B
15. Load Matrix A
16. Load Matrix B
17. A += B
18. A -= B
19. A *= B
0. Exit
   
How to Run
Using g++
g++ main.cpp -o matrix
./matrix
Using Visual Studio
Open project in Visual Studio
Build the project
Run the program
File Handling

The program supports:

Saving matrices into text files
Loading matrices from files
Persistent matrix storage
Exception Handling

The project handles errors such as:

Invalid matrix dimensions
Invalid operations
File opening errors
Dimension mismatch during operations
Future Improvements
GUI Version
Sparse Matrix Support
Real Matrix Inversion
Eigenvalue Calculation
Matrix Visualization
Scientific Calculator Integration
Author

Developed by Rohan Munir

License

This project is created for educational and learning purposes.

Source File

Main implementation
