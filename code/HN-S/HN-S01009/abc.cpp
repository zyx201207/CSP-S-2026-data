#include <bits/stdc++.h>

using namespace std;

int main() {
  auto st = clock();
  unsigned long long x = 1;
  for (int i = 1; i <= 1e8; i++) {
    x *= 2;
  }
  cout << x << '\n';
  cerr << clock() - st;
  return 0;
}
/*
g++ abc.cpp -o abc -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined && ./abc
*/