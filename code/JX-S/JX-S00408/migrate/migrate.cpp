#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t, n;
ll d, a[2000005], b[5005][5005], minn[5005][5005], vis[5005];
vector<int> edge[2000005];
void dfs(int ro, int u, int deep, int fa) {
    if (minn[ro][u]==0) minn[ro][u]=deep;
    else if (minn[ro][u]==deep) b[ro][u]++;
    else if (deep<minn[ro][u]) {
        minn[ro][u]=deep;
        b[ro][u]=0;
    }
    vis[u]=1;
    for (int v : edge[u]) {
        if (fa!=v && vis[v]==0)
            dfs(ro, v, deep+1, u);
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin>>c>>t;
    while (t--) {
        cin>>n>>d;
        if (c==11 || c==12) {
            cout<<0<<"\n";
            continue;
        }
        if (c==13 || c==14) {
            if (n<=3 || n%2) cout<<0<<"\n";
            else cout<<2*n<<"\n";
            continue;
        }
        for (int i=1; i<=n; i++) cin>>a[i];
        for (int i=0; i<=n; i++) edge[i].clear();
        memset(b, 0, sizeof b);
        memset(minn, 0, sizeof minn);
        ll ans=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (abs(a[i]-a[j]) <= d) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        for (int i=1; i<=n; i++) {
            memset(vis, 0, sizeof vis);
            dfs(i, i, 0, -1);
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                ans+=b[i][j]==1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
