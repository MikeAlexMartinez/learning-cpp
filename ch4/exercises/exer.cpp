#include "../../headers/std_lib_facilities.h"

void print_max_and_min(double a, double b);
void is_almost_equal(double a, double b);
void print_input(double input);
double is_smallest(double input, double smallest);
double is_largest(double input, double largest);

int main()
{
  bool largest_is_assigned = false;
  bool smallest_is_assigned = false;
  double largest = 0.0;
  double smallest = 0.0;

  double input = 0.0;
  // double val_two = 0;

  while (cin >> input)
  {
    print_input(input);

    if (!largest_is_assigned) {
      largest = input - 1;
      largest_is_assigned = true;
    }
    largest = is_largest(input, largest);

    if (!smallest_is_assigned) {
      smallest = input + 1;
      smallest_is_assigned = true;
    }
    smallest = is_smallest(input, smallest);

    // cout << val_one << " " << val_two << "\n";
    // print_max_and_min(val_one, val_two);
    // is_almost_equal(val_one, val_two);
  }
}

void print_input(double input) {
  cout << "value entered: " << input << "\n";
}

void test() {
  double val = 0.0;
  char unit1 = ' ';
  char unit2 = ' ';

  cin >> val >> unit1 >> unit2;
  cout << "entered: number of " << val << " and unit " << unit1 << unit2 << '\n';
}

double is_smallest(double input, double smallest) {
  if (input < smallest) {
    cout << "the smallest so far\n";
    return input;
  } else {
    return smallest;
  }
}

double is_largest(double input, double largest) {
  if (input > largest) {
    cout << "the largest so far\n";
    return input;
  } else {
    return largest;
  }
}

void print_max_and_min(double a, double b) {
  if (a == b) {
    cout << "the numbers are equal\n";
  } else if (b > a) {
    cout << "the smaller value is: " << a << "\n";
    cout << "the larger value is: " << b << "\n";
  } else {
    cout << "the smaller value is: " << b << "\n";
    cout << "the larger value is: " << a << "\n";
  }
  return;
}

void is_almost_equal(double a, double b)
{
  double diff = a - b;
  if (diff > -1 && diff < 1 && a != b) {
    cout << "the number are almost equal\n";
  }
  return;
}