#include "../headers/std_lib_facilities.h"

void getIntVector();
void getStringVector();
void pushToBack();

int main() {
  getIntVector();
  getStringVector();
  pushToBack();
  return 0;
}

void pushToBack() {
  vector<double> v;

  v.push_back(0.1);
  v.push_back(0.4);
  v.push_back(0.6);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
}

void getStringVector() {
  vector<string> philosopher = {"Kant", "Plato", "Hume", "Kierkegaard"};
  for (int i = 0; i < philosopher.size(); i++) {
    cout << philosopher[i] << '\n';
  }
}

void getIntVector() {
  vector<int> v = {2, 3, 4, 5, 6, 7};
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
}
