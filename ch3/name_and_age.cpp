#include "../headers/std_lib_facilities.h"

// read name and age
int main()
{
  cout << "Please enter your first name and age\n";
  string first_name;
  int age;
  // cin >> first_name;
  // cin >> age;
  // condenses to:
  cin >> first_name >> age;
  cout << "Hello, " << first_name << " (age " << age << ")\n";
}