#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

mt19937_64 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main() {
  freopen("migrate.in", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  using ll = long long;

  int tid = 0, tt = 10;
  cout << tid << ' ' << tt << '\n';
  for (; tt--; ) {
    int n = 100;
    ll d = 100;
    ll x = 0;
    cout << n << ' ' << d << '\n';
    for (int i = 1; i <= n; ++i) {
      x += rnd() % ll(d * 0.7) + ll(d * 0.3);
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}