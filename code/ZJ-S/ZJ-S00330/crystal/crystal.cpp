#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <ios>
#include <iostream>
#include <queue>
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
  std::queue<long long> q;
  q.emplace(0);
  long long sum = 0;
  std::size_t ans = 1;
  for (int i = 1; i < n; ++i) {
    sum += (a[i] - a[i - 1]) * q.size();
    while (!q.empty() && sum > m) {
      sum -= a[i] - a[q.front()];
      q.pop();
    }
    q.emplace(i);
    ans = std::max(ans, q.size());
  }
  std::cout << ans << '\n';
  return 0;
}
