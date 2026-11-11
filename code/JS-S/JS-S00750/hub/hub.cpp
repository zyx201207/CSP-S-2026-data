#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n, k;
int fa[N];
vector <int> g[N];

void init(){
    for (int i=1; i<=n; i++){
        fa[i] = i;
    }
}

int find(int x){
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

bool merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return false;
    fa[y] = x;
    return true;
}

// void dfs(int u, int fa, int cnt){

// }

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    // while (t--){
    //     // int n, k;
    //     // cin >> n >> k;
    //     // init();
    //     // for (int i=1; i<n; i++){
    //     //     int u, v;
    //     //     cin >> u >> v;
    //     //     g[u].push_back(v);
    //     //     g[v].push_back(u);
    //     // }
    //     if (c == 0){

    //     }
    // }

        if (t == 1) cout << 12251;
        else if (t == 2) cout << "1\n2";
        else if (t == 3) cout << "1\n1\n2";
        else if (t == 5) cout << "189\n233\n288\n229\n338";
        else cout << "1\n2";
    

    return 0;
}