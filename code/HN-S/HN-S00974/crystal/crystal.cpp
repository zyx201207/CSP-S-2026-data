#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 500010;
int n;
ll m;
ll a[maxn];
int main () {
  cin.tie (0)->sync_with_stdio (false);
  freopen ("crystal.in", "r", stdin);
  freopen ("crystal.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  sort (a + 1, a + n + 1);
  ll sum = 0;
  int ans = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    sum += a[i];
    while (a[i] * (i - j + 1) - sum > m) {
      sum -= a[j++];
    }
    ans = max (ans, i - j + 1);
  } 
  cout << ans;

  return 0;
}

/*
 g++ -std=c++14 -o2 crystal.cpp -o crystal && ./crystal
 diff -b -B crystal1.ans crystal.out
 */