#include "../headers/std_lib_facilities.h"

int square(int num);

int main() {
  for (int i = 0; i < 100; i++) {
    cout << i << '\t' << square(i) << '\n';
  }
}

int square(int num) {
  return num * num;
}
