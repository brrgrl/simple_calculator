// Write a calculator that takes a user's expression and returns a result
#include "std_lib_facilities.h"

int main() {

    // read a line
    cout << "Please enter expression (we can handle +,-,*,/)" << endl
         << "add an x to end expression (e.g., 1+2*3x)" << endl;
    cout << "Expression: ";
    int lval = 0;
    int rval ;
    char op;
    int res;
    cin >> lval;

    if (!cin) error("no first operand");

    for (char op; cin>>op;) {

        if (op!='x') cin >> rval;
        if (!cin) error ("no second operand");
        switch (op) {

        case '+':
            lval += rval;
            break;
        case '-':
            lval -= rval;
            break;
        case '*':
            lval *= rval;
            break;
        case '/':
            lval /= rval;
            break;
        default:
            cout << "Result: " << lval << endl;
            return 0;
        }
    }
    error("bad expression");
}
