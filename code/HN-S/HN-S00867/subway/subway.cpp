#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500005],k[505];
int a[505][150005],t[505][150005];
int minn = 0x3f3f3f3f3f3f,minnn = 0x3f3f3f3f3f3f;
vector<int> ch[500005];
unordered_map<int,int> vis[500005];
int goal_line[500005];
int pos = 0;
int c,n,m,d,q;
void dfs(int x,int line,int fa,int goal,int sum) {
    bool flag = 0;
    for (int i = 1; i <= pos; i++) {
        if (line == goal_line[i]) {
           flag = 1;
           break;
        }
    }
    if (flag == 1) {
        minn = min(minn,sum + t[line][goal]);
        return;
    }
    for (int i = 1; i <= k[line]; i++) {
        if (ch[a[line][i]].size() > 1) {
           for (int to : ch[a[line][i]]) {
               if (to != fa && to != line) {
                  dfs(a[line][i],to,line,goal,sum + t[line][a[line][i]] + t[to][a[line][i]]);
               }
           }
        }
    }
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1;j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][a[i][j]];
            vis[i][a[i][j]] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j][i] == 1) ch[i].push_back(j);
        }
    }
    while (q--) {
        int x,y;
        memset(goal_line,0,sizeof goal_line);
        pos = 0;
        minn = 0x3f3f3f3f3f3f,minnn = 0x3f3f3f3f3f3f;
        int ans = 0;
        cin >> x >> y;
        ans += w[x] + w[y];
        for (int i = 1; i <= n; i++) {
            if (vis[i][y]) goal_line[++pos] = i;
        }
         for (int i = 1; i <= n; i++) {
            if (vis[i][x]) dfs(x,i,0,y,0);
            minnn = min(minn + t[i][x],minnn);
            minn = 0x3f3f3f3f3f3f;
        }
        cout << ans + minnn << '\n';
    }
    return 0;
}
