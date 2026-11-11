#include <bits/stdc++.h>
using namespace std;


long long read()
{
  long long x = 0, f = 1;
  int c = getchar();
  while (c != EOF && !isdigit(c))
  {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c != EOF && isdigit(c))
  {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  return x * f;
}


const int N = 5e5 + 9;
int n;
long long m, a[N];


int main()
{
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  
  n = read(); m = read();
//  printf("%d %lld\n", n, m);
  for (int i = 1; i <= n; i ++)
  {
    a[i] = read();
//    printf("%lld ", a[i]);
  }
//  printf("\n");
  
  sort(a + 1, a + n + 1);
  int ans = 0;
  long long cnt = 0, cur = a[1];  // 当前区间已经使用cnt次操作,能量值都是cur 
  for (int l = 1, r = 1; r <= n; r ++)
  {
//    printf("[%d, %d]: ", l, r);
    cnt += (a[r] - cur) * (r - l);
//    printf("%d", cnt);
    while (cnt > m)
    {
      cnt -= a[r] - a[l];
      l ++;
//      printf("x\n[%d, %d]: %d", l, r, cnt);
    }
    ans = max(ans, r - l + 1);
    cur = a[r];
//    printf("\n");
  }
  printf("%d\n", ans);

  return 0;
}

