#include <iostream>
#include "Rational.h"
using namespace std;
int main() {
    Rational r1, r2, result;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input two Rational numbers\n";
        cout << "2. Addition (+)\n";
        cout << "3. Subtraction (-)\n";
        cout << "4. Multiplication (*)\n";
        cout << "5. Division (/)\n";
        cout << "6. Compare Rational numbers\n";
        cout << "7. Prefix Increment (++)\n";
        cout << "8. Prefix Decrement (--)\n";
        cout << "9. Unary Minus (-)\n";
        cout << "10. Unary Plus (+)\n";
        cout << "11. Logical NOT (!)\n";
        cout << "12. Assignment (=)\n";
        cout << "13. Simplify\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the first Rational number (numerator denominator): ";
            cin >> r1;
            cout << "Enter the second Rational number (numerator denominator): ";
            cin >> r2;
            break;
        case 2:
            result = r1 + r2;
            cout << "Addition result: " << result << endl;
            break;
        case 3:
            result = r1 - r2;
            cout << "Subtraction result: " << result << endl;
            break;
        case 4:
            result = r1 * r2;
            cout << "Multiplication result: " << result <<endl;
            break;
        case 5:
            result = r1 / r2;
            cout << "Division result: " << result << endl;
            break;
        case 6:
            if (r1 == r2)
                cout << "Rational numbers are equal.\n";
            else
                cout << "Rational numbers are not equal.\n";
            break;
        case 7:
            ++r1;
            cout << "Prefix Increment result: " << r1 <<endl;
            break;
        case 8:
            --r1;
            cout << "Prefix Decrement result: " << r1 << endl;
            break;
        case 9:
            result = -r1;
            cout << "Unary Minus result: " << result <<endl;
            break;
        case 10:
            result = +r1;
            cout << "Unary Plus result: " << result <<endl;
            break;
        case 11:
            if (!r1)
                cout << "Logical NOT: Rational number is zero.\n";
            else
                cout << "Logical NOT: Rational number is not zero.\n";
            break;
        case 12:
            r1 = r2;
            cout << "Assignment (=) result: " << r1 << endl;
            break;
        case 13:
            r1.simplify();
            cout << "Simplified Rational number: " << r1 << endl;
            break;
        case 14:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 14);

    return 0;
}
