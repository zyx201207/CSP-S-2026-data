
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[50005];
int ans[50000],b[50050];
int n, m;
int q[10005], cnt;

int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
       scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
       for (int j = i; j <= n; j++) {
            int k = a[j];
            if (b[k] != 0) {
                int gg = b[k];
                for (int l = b[k]; l <= cnt; l++)
                     b[q[l]] = 0;
                cnt = gg - 1;
                q[++cnt] = a[j];
                b[a[j]] = cnt;
            }
            else
               q[++cnt] = a[j], b[a[j]] = cnt;

       }
       for (int k = 1; k <= cnt; k++)
            ans[q[k]]++;
       memset(q, 0, sizeof(q));
       memset(b, 0, sizeof(b));
       cnt = 0;

  }
  for (int i = 1; i <= m; i++)
       printf("%d\n", ans[i]);
return 0;}
