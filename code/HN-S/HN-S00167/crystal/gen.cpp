#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL randint(LL b) {
  return ((unsigned long long)rand() * rand() * rand() * rand() * rand()) % b + 1;
}

int main() {
  ofstream fout("gen.out");
  srand(time(0));
  LL n = 5000, m = randint(1000000000000);
  fout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    fout << randint(2000000000000) - 1000000000000 << ' ';
  }
  return 0;
}