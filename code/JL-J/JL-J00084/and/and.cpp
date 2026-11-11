
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, ans, ma = -1, g;
int a[200005], c[200005];

inline void dfs(int x) {
       if (x == n + 1) {
           g = 0;
           for (int i = 1; i <= n; i++)
                if (c[i] == 1)
                    ++g;
           if (g == m) {
               ans = 0;
               for (int i = 1; i <= n; i++)
                    if (c[i]) {
                        if (!ans)
                            ans = a[i];
                        else
                            ans &= a[i];
                    }
               ma = max(ma, ans);
           }
           return;
    }
       if (x == n + 1)
           return;
       c[x] = 0;
       dfs(x + 1);
       c[x] = 1;
       dfs(x + 1);
}

int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
         scanf("%d", &a[i]);
    dfs(1);
    printf("%d", ma);
return 0;}
