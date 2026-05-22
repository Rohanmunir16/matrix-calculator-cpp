#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<cmath>

using namespace std;

// Base class: Matrix
class Matrix {
public:
    double** data;
    int rows, cols;

    // Helper function to allocate memory
    void allocateMemory(int r, int c) {
        if (r <= 0 || c <= 0) {
            throw string("Matrix dimensions must be positive integers.");
        }
        rows = r;
        cols = c;
        data = new double* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];  // Allocate memory for each row
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;  // Initialize each element to 0
            }
        }
    }

    // Helper function to deallocate memory
    void deallocateMemory() {
        if (data) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
            data = NULL;
        }
    }

public:

    // Input matrix from keyboard
    void inputFromKeyboard() {
        try {
            cout << "Enter the number of rows and columns: ";
            cin >> rows >> cols;
            if (rows <= 0 || cols <= 0) {
                throw string("Matrix dimensions must be positive integers.");
            }
            allocateMemory(rows, cols);
            cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cin >> data[i][j];
                }
            }
        }
        catch (const string& e) {
            cout << "Error: " << e << endl;
        }
    }

    // Display the matrix
    void display() const {
        if (data == NULL) {
            cout << "Error: Matrix not entered yet!" << endl;
            return;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << setw(8) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Add matrices
    void addMatrices(Matrix& other) {
        try {
            if (rows != other.rows || cols != other.cols) {
                throw string("Matrix dimensions must match for addition.");
            }
            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            cout << "Result of A + B:" << endl;
            result.display();
        }
        catch (const string& e) {
            cout << "Error: " << e << endl;
        }
    }

    // Subtract matrices
    void subtractMatrices(Matrix& other) {
        try {
            if (rows != other.rows || cols != other.cols) {
                throw string("Matrix dimensions must match for subtraction.");
            }
            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] - other.data[i][j];
                }
            }
            cout << "Result of A - B:" << endl;
            result.display();
        }
        catch (const string& e) {
            cout << "Error: " << e << endl;
        }
    }

    // Multiply matrices
    void multiplyMatrices(Matrix& other) {
        try {
            if (cols != other.rows) {
                throw string("Matrix dimensions do not match for multiplication.");
            }
            Matrix result(rows, other.cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < other.cols; j++) {
                    for (int k = 0; k < cols; k++) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            cout << "Result of A * B:" << endl;
            result.display();
        }
        catch (const string& e) {
            cout << "Error: " << e << endl;
        }
    }

    // Multiply by scalar
    void multiplyScalar(double scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        cout << "Result of A * scalar:" << endl;
        result.display();
    }

    // Save matrix to a file
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << rows << " " << cols << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    file << data[i][j] << " ";
                }
                file << endl;
            }
            file.close();
            cout << "Matrix saved to file: " << filename << endl;
        }
        else {
            cout << "Error: Could not open file to save matrix!" << endl;
        }
    }

    // Load matrix from a file
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            file >> rows >> cols;
            allocateMemory(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    file >> data[i][j];
                }
            }
            file.close();
            cout << "Matrix loaded from file: " << filename << endl;
        }
        else {
            cout << "Error: Could not open file to load matrix!" << endl;
        }
    }

    // Transpose the matrix
    void transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        cout << "Transpose of Matrix:" << endl;
        result.display();
    }

    // Check equality of matrices
    void checkEquality(Matrix& other) {
        try {
            if (rows == 0 || cols == 0 || other.rows == 0 || other.cols == 0) {
                throw string("Both matrices must be defined before performing operations.");
            }

            if (rows != other.rows || cols != other.cols) {
                throw string("Matrix dimensions must match for equality check.");
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (data[i][j] != other.data[i][j]) {
                        throw string("Matrices are not equal.");
                    }
                }
            }
            cout << "Matrices are equal." << endl;
        }
        catch (const string& e) {
            cout << "Error: " << e << endl;
        }
    }

    // Constructor
    Matrix(int r = 0, int c = 0) : rows(r), cols(c), data(nullptr) {
        if (r > 0 && c > 0) {
            allocateMemory(r, c);
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) {
        allocateMemory(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Destructor
    ~Matrix() {
        deallocateMemory();
    }

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            deallocateMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    // Addition assignment operator
    Matrix& operator+=(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw string("Matrix dimensions must match for addition.");
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }


    Matrix& operator-=(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw string("Matrix dimensions must match for subtraction.");
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

   
    Matrix& operator*=(const Matrix& other) {
        if (cols != other.rows) {
            throw string("Matrix dimensions must match for multiplication.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }
};

class SquareMatrix : public Matrix {
public:
   
    SquareMatrix(int size) : Matrix(size, size) {}

    SquareMatrix(Matrix& m) : Matrix(m) {
        if (m.rows != m.cols) {
            throw string("Matrix is not square.");
        }
    }

   
    double determinant() {
        if (rows != cols) {
            cout << "Determinant is only defined for square matrices." << endl;
            return 0;
        }
        return calculateDeterminant(data, rows);
    }

    void inverse() {
        if (rows != cols) {
            cout << "Inverse is only defined for square matrices." << endl;
            return;
        }
        SquareMatrix result(rows);
        for (int i = 0; i < rows; i++) {
            result.data[i][i] = 1;  
        }
        cout << "Inverse Matrix (stub):" << endl;
        result.display();
    }

private:

    double calculateDeterminant(double** mat, int n) const {
        if (n == 1) {
            return mat[0][0]; 
        }

        if (n == 2) { 
            return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
        }

       
        double det = 0.0;
        for (int col = 0; col < n; ++col) {
           
            double** minor = new double* [n - 1];
            for (int i = 0; i < n - 1; ++i) {
                minor[i] = new double[n - 1];
            }

            for (int i = 1; i < n; ++i) {
                int minorCol = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == col) continue;
                    minor[i - 1][minorCol++] = mat[i][j];
                }
            }

            
            det += pow(-1, col) * mat[0][col] * calculateDeterminant(minor, n - 1);

         
            for (int i = 0; i < n - 1; ++i) {
                delete[] minor[i];
            }
            delete[] minor;
        }

        return det;
    }
};


int main() {
    Matrix A, B;
    int choice;
    double scalar;
    string userInput, filename;

    bool showMenu = true;
    do {
       
        if (showMenu) {
            cout << "\nMatrix Calculator Menu:" << endl;
            cout << "1. Input Matrix A from Keyboard" << endl;
            cout << "2. Input Matrix B from Keyboard" << endl;
            cout << "3. Display Matrix A" << endl;
            cout << "4. Display Matrix B" << endl;
            cout << "5. Add Matrices (A + B)" << endl;
            cout << "6. Subtract Matrices (A - B)" << endl;
            cout << "7. Multiply Matrices (A * B)" << endl;
            cout << "8. Multiply Matrix A by Scalar" << endl;
            cout << "9. Check Equality of Matrices (A == B)" << endl;
            cout << "10. Transpose Matrix" << endl;
            cout << "11. Calculate Determinant of Matrix" << endl;
            cout << "12. Calculate Inverse of Matrix" << endl;
            cout << "13. Save Matrix A to File" << endl;
            cout << "14. Save Matrix B to File" << endl;
            cout << "15. Load Matrix A from File" << endl;
            cout << "16. Load Matrix B from File" << endl;
            cout << "17. Add Matrix B to Matrix A (A += B)" << endl;
            cout << "18. Subtract Matrix B from Matrix A (A -= B)" << endl;
            cout << "19. Multiply Matrix A by Matrix B (A *= B)" << endl;
            cout << "0. Exit" << endl;
        }

        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Input Matrix A:" << endl;
                A.inputFromKeyboard();
                break;
            case 2:
                cout << "Input Matrix B:" << endl;
                B.inputFromKeyboard();
                break;
            case 3:
                cout << "Matrix A:" << endl;
                A.display();
                break;
            case 4:
                cout << "Matrix B:" << endl;
                B.display();
                break;
            case 5:
                A.addMatrices(B);
                break;
            case 6:
                A.subtractMatrices(B);
                break;
            case 7:
                A.multiplyMatrices(B);
                break;
            case 8:
                cout << "Enter scalar value: ";
                cin >> scalar;
                A.multiplyScalar(scalar);
                break;
            case 9:
                A.checkEquality(B);
                break;
            case 10:
                cout << "Which matrix do you want to transpose? (1 for Matrix A, 2 for Matrix B): ";
                int matrixChoice;
                cin >> matrixChoice;
                if (matrixChoice == 1) {
                    A.transpose();
                }
                else if (matrixChoice == 2) {
                    B.transpose();
                }
                break;
            case 11:
                cout << "Which matrix do you want to calculate the determinant of? (1 for Matrix A, 2 for Matrix B): ";
                cin >> matrixChoice;
                if (matrixChoice == 1) {
                    try {
                        SquareMatrix sqMatrixA(A);
                        cout << "Determinant of Matrix A: " << sqMatrixA.determinant() << endl;
                    }
                    catch (const string& e) {
                        cout << "Error: " << e << endl;
                    }
                }
                else if (matrixChoice == 2) {
                    try {
                        SquareMatrix sqMatrixB(B);
                        cout << "Determinant of Matrix B: " << sqMatrixB.determinant() << endl;
                    }
                    catch (const string& e) {
                        cout << "Error: " << e << endl;
                    }
                }
                break;
            case 12:
                cout << "Which matrix do you want to calculate the inverse of? (1 for Matrix A, 2 for Matrix B): ";
                cin >> matrixChoice;
                if (matrixChoice == 1) {
                    try {
                        SquareMatrix sqMatrixA(A);
                        sqMatrixA.inverse();
                    }
                    catch (const string& e) {
                        cout << "Error: " << e << endl;
                    }
                }
                else if (matrixChoice == 2) {
                    try {
                        SquareMatrix sqMatrixB(B);
                        sqMatrixB.inverse();
                    }
                    catch (const string& e) {
                        cout << "Error: " << e << endl;
                    }
                }
                break;
            case 13:
                cout << "Enter filename to save Matrix A: ";
                cin >> filename;
                A.saveToFile(filename);
                break;
            case 14:
                cout << "Enter filename to save Matrix B: ";
                cin >> filename;
                B.saveToFile(filename);
                break;
            case 15:
                cout << "Enter filename to load Matrix A from: ";
                cin >> filename;
                A.loadFromFile(filename);
                A.display();
                break;
            case 16:
                cout << "Enter filename to load Matrix B from: ";
                cin >> filename;
                B.loadFromFile(filename);
                B.display();
                break;
            case 17:
                cout << "Adding Matrix B to Matrix A (A += B):" << endl;
                A += B;
                A.display();
                break;
            case 18:
                cout << "Subtracting Matrix B from Matrix A (A -= B):" << endl;
                A -= B;
                A.display();
                break;
            case 19:
                cout << "Multiplying Matrix A by Matrix B (A *= B):" << endl;
                A *= B;
                A.display();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                throw string("Invalid choice! Please try again.");
            }

            cout << "\nDo you want to perform another calculation or see the menu again? (yes(y)/menu(m)/no(n)): ";
            cin >> userInput;

            for (char& c : userInput) {
                c = tolower(c);
            }

            if (userInput == "y") {
                showMenu = false;
            }
            else if (userInput == "m") {
                showMenu = true;
            }
            else if (userInput == "n") {
                cout << "Exiting program..." << endl;
                break;
            }
            else {
                cout << "Invalid input, exiting program." << endl;
                break;
            }
        }
        catch (const string& e) {
            cout << "Error: " << e << endl;
        }
    } while (choice != 0);

    return 0;
}
