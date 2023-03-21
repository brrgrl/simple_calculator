// Write a calculator that takes a user's expression and returns a result
#include "std_lib_facilities.h"

/** Use tokens to store whether it is an operator or a number
    operators get stored in kind, e.g., '+', '-', '*', '/'
    and number have a kind of '#'
*/
class Token {
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0) {  }
    Token(char ch, double val)
        :kind(ch), value(val) {  }
};

double expression();
double primary();
Token get_token();
double term();
double previous = 0;

double expression() {
    double left = term();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = get_token();
            break;
        case '-':
            left -= term();
            t = get_token();
            break;
        case ';':
            cin.clear();
            previous = left;
            return left;
        default:
            cin.putback(t.kind);
            return left;
    }
  }
  return left;
};

double term() {
    double left = primary();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/': {
            double d = primary();
            if (d==0) error("divide by zero");
            left /= d;
            t = get_token();
            break;
        }
        default:
            cin.putback(t.kind);
            return left;
        }
    }
};

double primary() {
    Token t = get_token();
    switch (t.kind) {
    case '(':
        {
            double d = expression();
            cout << "parens: " << d << endl;
            t = get_token();
            if (t.kind!=')') error("')' expected");
            return d;
        }
    case '#':
        return t.value;
    default:
        cin.putback(t.kind);
        return previous;
    }
    return 1;
}


Token get_token() {

    char ch;
    cin >> ch;
    switch (ch) {

    case '(': case ')': case '+': case '-': case '*': case '/': case ';':
        return Token(ch);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token('#', val);
        }
    default:
        error("Bad token");
    }
    return 1;
}


int main() {
    try {
        while (cin) {
            cout << previous << "->" << expression() << endl;
        }
    }
    catch (exception& e) {

        cerr << e.what() << endl;
        return 1;
    }
    catch (...) {

        cerr << "exception" << endl;
        return 2;
    }
}
