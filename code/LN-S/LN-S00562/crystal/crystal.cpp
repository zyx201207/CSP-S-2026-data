#include <bits/stdc++.h>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::freopen("crystal.in", "r", stdin);
  std::freopen("crystal.out", "w", stdout);
  int n;
  long long m;
  std::cin >> n >> m;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  std::sort(a.begin(), a.end());
  int l = 0;
  long long sum = 0;
  int res = 1;
  for (int r = 1; r < n; ++r)
  {
    sum += (r - l) * (a[r] - a[r - 1]);
    while (sum > m)
      sum -= a[r] - a[l], ++l; 
    res = std::max(res, r - l + 1);
  }
  std::cout << res << '\n';
  return 0;
}