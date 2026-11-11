#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e6 + 10;
typedef long long ll;
typedef pair<int,int> PII;
vector<vector<int>> adj(N);

int a[N];
int l[N];
ll w[N];
ll ans[N];
ll sz[N];

void dfs(int u) {
    sz[u] = 1;
    for(int i = 0; i < adj[u].size(); i ++) {
        int v = adj[u][i];
        dfs(v);
        sz[u] += sz[v];
    }
    ans[a[u]] += sz[u];
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = n; i >= 1; i --) {
        if(l[a[i]] == 0) {
            l[a[i]] = i;
        }
        adj[l[a[i]] + 1].push_back(i);
    }
    dfs(n + 1);
    for(int i = 1; i <= m; i ++) {
        cout << ans[i];
        if(i != m) cout << " ";
        else cout << endl;
    }
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
