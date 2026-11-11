#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main()
{
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  i64 ans = 0;
  std::vector<int> a(n + 1);
  std::vector<char> ch(n + 1);
  for (int i = 1; i <= n; i++)
  {
    std::cin >> a[i] >> ch[i];
  }
  int head = 0, tail = 0;
  int i = 1, j = n;
  while (i <= j)
  {
    if (head == 0)
      head = a[i];
    if (tail == 0)
      tail = a[j];
    // head = a[i], tail = a[j];
    if (ch[i] == ch[j])
    {
      if (head > tail)
      {
        head -= tail;
        tail = 0;
        j--;
      }
      else if (head < tail)
      {
        tail -= head;
        head = 0;
        i++;
      }
      else
      {
        i++, j--;
        head = 0, tail = 0;
      }
    }
    else
    {
      if (head > tail)
      {
        ans += tail;
        head -= tail;
        tail = 0;
        j--;
      }
      else if (head < tail)
      {
        ans += head;
        tail -= head;
        head = 0;
        i++;
      }
      else
      {
        ans += tail;
        i++, j--;
        head = 0, tail = 0;
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}