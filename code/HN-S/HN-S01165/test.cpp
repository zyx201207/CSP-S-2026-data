#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int main() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  return 0;
}

/*
J - T4 Solution?

F(rev(a)) == F(a)? false.
F([1, 3, 2, 1, 2]) = [1, 2] != rev F(2, 1, 2, 3, 1) = rev[2, 3, 1]

if (nxt[i] != end())  F[i, n] = i + F[nxt[i] + 1, n]
build, solve.
*/