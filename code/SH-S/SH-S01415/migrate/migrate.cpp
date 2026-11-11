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


const int N = 2e6 + 9;
int n;
long long d, x[N];
int jump[N];  // i岛屿最远能飞到编号为jump[i]的岛屿 


int main()
{
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  
  int C = read(), T = read();
  while (T --)
  {
    n = read(); d = read();
    int idx = 1;
    for (int i = 1; i <= n; i ++)
    {
      x[i] = read();
      while (x[i] - x[idx] > d) jump[idx ++] = i - 1;
    }
    for (int i = idx; i <= n; i ++) jump[i] = n;
//    for (int i = 1; i <= n; i ++) printf("%d ", jump[i]);
    
    for (int i = 1; i <= n; i ++)
    {
      for (int j = i + 1; j <= n; j ++)
      {
        dfs(i, j, 0);
      }
    }
    
    printf("\n");
  }

  return 0;
}

