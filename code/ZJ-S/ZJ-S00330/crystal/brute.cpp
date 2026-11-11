#include <algorithm>
#include <cstdio>
#include <ios>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
  std::ignore = std::freopen("crystal.in", "r", stdin);
  std::ignore = std::freopen("crystal.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  long long m;
  std::cin >> n >> m;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    long long sum = 0;
    int j = i - 1;
    for (; j >= 0; --j) {
      if (sum + a[i] - a[j] > m) {
        break;
      } else {
        sum += a[i] - a[j];
      }
    }
    ans = std::max(ans, i - j);
  }
  std::cout << ans << '\n';
  return 0;
}
