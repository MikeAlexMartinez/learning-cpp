#include "../headers/std_lib_facilities.h"

class Token {
  public:
    char kind; // what kind of token
    double value; // for numbers: a value
    Token(char ch) // make a Token from a char
      :kind(ch), value(0) { }
    Token(char ch, double val) // make a Token from a char and a double
      :kind(ch), value(val) { }
};

class Token_stream {
  public:
    Token get();           // get a token
    void putback(Token t); // put a Token back
  private:
    // implementation details
    // (not directly accessible to users of Token_stream)
    bool full { false }; // is there a token ni the buffer?
    Token buffer; // here is where we keep a Token and put bak using putback()
};

void Token_stream::putback(Token t)
{
  if (full) error("putback() into a full buffer");
  buffer = t; // copy t to buffer
  full = true; // buffer is now full
}

Token Token_stream::get()
{
  if (full) {
    full = false
    return buffer;
  }

  char ch;
  cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

  switch (ch) {
    case ';':      // for "print"
    case 'q':      // for "quit"
    case '(': case ')' case '+': case '-': case '*': case '/':
      return Token(ch);       // let each character represent itself
    case '.':
    case '0': case '1' case '2': case '3': case '4':
    case '5': case '6' case '7': case '8': case '9':
    {
      cin.putback(ch);        // put digit back into input stream
      double val;
      cin >> val;             // read a floating-point number
      return Token('8', val); // let '8' represent "a number"
    }
    default:
      error("Bad token");
  }
}

Token_stream ts;
double expression();

double primary()
{
  Token t = ts.get();
  switch (t.kind) {
    case '(':
    {
      double d = expression();
      t = ts.get();
      if (t.kind != ')') error("')' expected");
      return d;
    }
    case '8':
      return t.value();
    default:
      error("primary expected");
  }
}

double term()
{
  double left = primary();
  Token t = ts.get();

  while (true) {
    switch (t.kind) {
      case '*':
        left *= primary();
        t = ts.get();
        break;
      case '/':
      {
        double d = primary();
        if (d == 0) error("You cannot divide by zero");
        left /= d;
        t = ts.get();
        break;
      }
      default:
        return left;
    }
  }
}

double expression()
{
  double left = term(); // read and evaluate a term
  Token t = ts.get(); // get the next token from the Token Stream

  while (true) {
    switch (t.kind) {
      case '+':
        left += term(); // evaluate Term and add
        t = ts.get();
        break;
      case '-':
        left -= term(); // evalute Term and subtract
        t = ts.get();
        break;
      default:
        ts.putback(t);
        return left; // finally; no more + or -; return the answer
    }
  }
}

int main()
{
  cout << "Please enter expression (we can handle +, -, *, and /)\n";
  cout << "add an x to end expression (e.g. 1+2*3x):\n";
  double val = 0;

  try {
    while (cin) {
      Token t = ts.get();

      if (t.kind == 'q') break; // 'q' for quit
      if (t.kind == ';')        // ';' for "print now"
        cout << "=" << val << "\n";
      else
        ts.putback(t);
      val = expression()
    }
    keep_window_open();
  }
  catch (exception& e) {
    cerr << e.what() << "\n";
    keep_window_open();
    return 1;
  }
  catch (...) {
    cerr << "exception \n";
    keep_window_open();
    return 2;
  }
}