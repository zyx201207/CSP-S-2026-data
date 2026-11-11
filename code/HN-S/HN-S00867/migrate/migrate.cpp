#include <bits/stdc++.h>
using namespace std;
int c,t;
int a[2005];
bool f[2005];
int n,d;
int ans = 0;
void dfs(int start,int x,int y) {
    if (x == y) {
       int last = 0,sum = 0;
       for (int i = start; i <= y; i++) {
           if (f[i] == 1) sum++;
       }
       bool flag = 0;
       for (int i = start; i <= y; i++) {
           if (f[i] == 1) {
              if (last == 0) last = a[i];
              else {
                 if (a[i] - last > d && a[i] - last > sum - 1) {
                    flag = 1;
                    break;
                 }
                 last = a[i];
              }
           }
       }
       if (!flag) {
          ans++;
       }
       return;
    }
    if (x == start) {
        dfs(start,x + 1,y);
    } else if (x + 1 == y) {
        dfs(start,x + 1,y);
    } else {
        for (int i = x; i <= y; i++) {
           if (f[i]) continue;
           f[i] = 1;
           dfs(start,i,y);
           f[i] = 0;
        }
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--) {
        int cnt = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                memset(f,0,sizeof f);
                ans = 0;
                f[i] = 1,f[j] = 1;
                dfs(i,i,j);
                if (ans == 2) cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
