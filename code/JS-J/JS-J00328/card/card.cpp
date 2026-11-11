#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int n, m;
int a[300100];

std::mt19937 rnd(std::time(0));

int main()
{
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];
  for (int game = 1; game <= n; game++)
  {
    std::cout << game << " ";
  }
  return 0;
}