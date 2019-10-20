#include "../headers/std_lib_facilities.h"

class Token {
  public:
    char kind;
    double value;
};

double expression()
{
  double left = expression();
  Token t = get_token();

  switch (t.kind) {
    case '+':
      return left + term();
    case '-':
      return left - term();
    default:
      return left;
  }
}

int main()
{
  cout << "Please enter expression (we can handle +, -, *, and /)\n";
  cout << "add an x to end expression (e.g. 1+2*3x):\n";
  int lval = 0;
  int rval;

  cin >> lval;

  if (!cin) error("no first operand");
  for (char op; cin>>op; ) { // read operator and rigt-hand operand repeatedly

    if (op != 'x') cin >> rval;
    if (!cin) error("no second operand");
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
        cout << "Result: " << lval << "\n";
        keep_window_open();
        return 0;
    }
  }
  error("bad expression");
}