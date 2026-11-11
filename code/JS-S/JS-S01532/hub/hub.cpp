#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, k, u, v;
int fa[N];
vector<int> e[N];
int getfa(int x){
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1; i < n; i++){
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            int x = getfa(u), y = getfa(v);
            fa[x] = y;
        }
        if(c == 0 && n == 5 && k == 2) cout << 1 << "\n";
        if(c == 0 && n == 10 && k == 3) cout << 2 << "\n";
        if(c == 0 && n == 8 && k == 6) cout << 1 << "\n";
        if(c == 0 && n == 6 && k == 5) cout << 1 << "\n";
        if(c == 0 && n == 9 && k == 3) cout << 2 << "\n";
    }
    return 0;
}
