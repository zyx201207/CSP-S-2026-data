#include <bits/stdc++.h>
int mainf(int)
{
  int n;
  long long d;
  std::cin >> n >> d;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  // lc: first a[i] >= a[r - 1] - d
  std::vector<int> lc(n + 2);
  {
    int l = 0;
    for (int r = 0; r < n; ++r)
    {
      while (a[l] < a[r] - d) ++l;
      lc[r + 1] = l;
    }
  }
  lc[0] = -1;
  lc[n + 1] = n;
  // rc: last a[i] <= a[l - 1] + d
  std::vector<int> rc(n + 2);
  {
    int r = n - 1;
    for (int l = n - 1; l >= 0; --l)
    {
      while (a[r] > a[l] + d) --r;
      rc[l + 1] = r;
    }
  }
  rc[0] = -1;
  rc[n + 1] = n;

  // for (int i = 0; i <= n + 1; ++i)
  //   std::cerr << lc[i] << ' ';
  // std::cerr << '\n';
  // for (int i = 0; i <= n + 1; ++i)
  //   std::cerr << rc[i] << ' ';
  // std::cerr << '\n';

  std::vector<int> backward(n, 0);
  auto go_backward = [&](int l, int r)
    { return (r - l + 1) + backward[l]; };
  for (int i = 0; i < n; ++i)
  {
    int l = lc[i + 1];
    int r = std::min(i - 1, lc[i + 2] - 1);
    // std::cerr << l << ' ' << r << '\n';
    if (l <= r)
      backward[i] = go_backward(l, r);
  }
  // std::cerr << '\n';
  std::vector<int> forward(n, 0);
  auto go_forward = [&](int l, int r)
    { return (r - l + 1) + forward[r]; };
  for (int i = n - 1; i >= 0; --i)
  {
    int l = std::max(i + 1, rc[i] + 1);
    int r = rc[i + 1];
    // std::cerr << l << ' ' << r << '\n';
    if (l <= r)
      forward[i] = go_forward(l, r);
  }
  // std::cerr << '\n';

  // for (int i = 0; i < n; ++i)
  //   std::cerr << backward[i] << ' ';
  // std::cerr << '\n';
  // for (int i = 0; i < n; ++i)
  //   std::cerr << forward[i] << ' ';
  // std::cerr << '\n';

  long long res = 0;
  for (int i = 0; i + 1 < n; ++i)
  {
    int ll = lc[i + 2];
    int lr = std::min(i - 1, lc[i + 3] - 1);
    int rl = std::max(i + 2, rc[i] + 1);
    int rr = rc[i + 1];
    // std::cerr << ll << ' ' << lr << ' ' << rl << ' ' << rr << '\n';
    if (!(ll <= lr && rl <= rr)) continue;
    long long cur = 1;
    if (lc[i + 1] == lc[i + 2]) cur *= go_backward(ll, lr);
    else                        cur *= (lr - ll + 1);
    if (rc[i + 1] == rc[i + 2]) cur *= go_forward(rl, rr);
    else                        cur *= (rr - rl + 1);
    res += cur;
    // std::cerr << res << '\n';
  }
  // std::cerr << '\n';
  std::cout << res << '\n';
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::freopen("migrate.in", "r", stdin);
  std::freopen("migrate.out", "w", stdout);
  int c, t;
  std::cin >> c >> t;
  while (t--)
    mainf(c);
  return 0;
}