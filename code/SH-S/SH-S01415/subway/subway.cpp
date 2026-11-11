#include <bits/stdc++.h>
using namespace std;


int read()
{
  int x = 0, f = 1;
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


const int N = 209, M = 409, D = 29;
int n, m, w[M];  // 口->厅的距离 
int k[N];  // 路线经过的地铁站数 
int a[M], t[M];  // 每站的站点编号,厅->台的距离 
// 口->厅->台 

struct stru
{
  vector <int> idx;  // 线路 
  vector <long long> time;  // 距离 
} tin[M];  // 站厅 
long long e[M][D][M][D];  // e[i][j][k][l]:i厅j线->k厅l线的距离 


int main()
{
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  
  int c, d, Q;
  c = read(); n = read(); m = read(); d = read(); Q = read();
  for (int i = 1; i <= m; i ++)
  {
    w[i] = read();
  }
  memset(e, 0x3f, sizeof(e));
  for (int i = 1; i <= n; i ++)
  {
    k[i] = read();
    for (int j = 0; j < k[i]; j ++)
    {
      a[j] = read();
      t[j] = read();
      tin[a[j]].idx.push_back(i);
      tin[a[j]].time.push_back(t[j]);
      
      for (int k = 0; k < j; k ++)  // 同一条线路距离为0 
      {
        e[a[j]][i][a[k]][i] = 0;
        e[a[k]][i][a[j]][i] = 0;
      }
    }
  }
  
  for (int i = 1; i <= m; i ++)
  {
    for (int j = 0; j < tin[i].idx.size(); j ++)
    {
      for (int k = 0; k < j; k ++)
      {
        long long tmp = tin[i].time[j] + tin[i].time[k];
        e[i][tin[i].idx[j]][i][tin[i].idx[k]] = tmp;
        e[i][tin[i].idx[k]][i][tin[i].idx[j]] = tmp;
      }
    }
  }
  
  for (int i = 1; i <= m; i ++)  // 厅 
    for (int ii : tin[i].idx)  // 线 
    {
      for (int j = 1; j <= m; j ++) 
        for (int jj : tin[j].idx)
        {
          for (int k = 1; k <= m; k ++) 
            for (int kk : tin[k].idx)
            {
              e[j][jj][k][kk] = min(e[j][jj][k][kk], e[j][jj][i][ii] + e[i][ii][k][kk]);
            }
        }
    }
  
  while (Q --)
  {
    int x = read(), y = read();
    long long ans = LONG_LONG_MAX;
    for (int i : tin[x].idx)
    {
      for (int j : tin[y].idx)
      {
        ans = min(ans, e[x][i][y][j]);
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}

