#include "../headers/std_lib_facilities.h"

int main() {
  vector<double> temps;
  for(double temp; cin >> temp; )
    temps.push_back(temp);

  // compute mean temperature
  double sum = 0;
  for (double x : temps) sum += x;
  cout << "Average Temperature: " << sum/temps.size() << '\n';

  // compute median temperature
  sort(temps);
  cout << "Median temperature: " << temps[temps.size()/2] << '\n';
}