#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6+5;
int cc,t;
int dis[10005][10005],ans[10005][10005];
vector<int> mp[N];

void dfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int nxt:mp[now]) {
            if (dis[x][nxt] == 0 || dis[x][now] + 1 < dis[x][nxt]) {
                dis[x][nxt] = dis[x][now] + 1;
                q.push(nxt);
                ans[x][nxt] = 1;
            }
            if (dis[x][now] + 1 == dis[x][nxt]) {
                ans[x][nxt] ++;
            }
        }
    }
}
void solve() {
    int sum = 0,n,d;
    ll p[N];
    cin >> n >> d;
    for (int i = 1;i <= n;i++) cin >> p[i];
    for (int i = 1;i <= n;i++) {
        for (int j = i+1;j <= n;j++) {
            if (p[j] - p[i] <= d) {
                mp[i].push_back(j);
                dis[i][j] = 1;
            } else break;
        }
    }
    for (int i = 1;i <= n;i++) {
        dfs(i);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = i+1;j <= n;j++) {
            if (ans[i][j] == 2) {
                sum ++;
            }
        }
    }
    cout << sum << "\n";
    memset(dis,0,sizeof(dis));
    memset(ans,0,sizeof(dis));
    for(int i = 1;i <= n;i++) mp[i].resize(0);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> cc >> t;
    while (t--) solve();
    return 0;
}

