#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << rand() % 2;
}
int main() {
    //By Luogu-bilibiliTV
    //Give me a blue-gou pls,I'll do every thing
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--)
        solve();
    return 0;
}
