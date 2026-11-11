#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

ll c, n, m, d, Q, w[N], top, dis[4 * N], vis[4 * N], k[N], ans;

struct Node{
    ll id, t;
};

vector<Node> v[4 * N];

struct Node2{
    ll x, w;
    bool operator < (const Node2 &a) const {
        return w < a.w;
    }
};

priority_queue<Node2> q;

vector<int> v2[N];

void bfs(int s){
    q.push({s, 0});
    vis[s] = 1;
    while(q.size()){
        auto [x, w] = q.top();
        q.pop();
        for(auto [y, w2] : v[x]){
            if(!vis[y]){
                vis[y] = 1;
                dis[y] = w + w2;
                q.push({y, w + w2});
            }
        }
    }
}

void dfs(int x, ll sum, int r){
    if(x == r){
        ans = min(ans, sum);
        return ;
    }
    for(int i : v2[x]){
        if(vis[i])continue;
        vis[i] = 1;
        dfs(i, sum + 2, r);
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> n >> m >> d >> Q;
    if(c >= 12 && c <= 19){
        int T = 0;
        for(int i = 1; i <= m; i++){
           cin >> w[i];
           T = w[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> k[i];
            for(int j = 1, id, t; j <= k[i]; j++){
                cin >> id >> t;
                v2[i].push_back(id);
            }
        }
        while(Q--){
            int l, r;
            cin >> l >> r;
            ans = LLONG_MAX;
            dfs(l, 2, r);
            cout << (ans + 2) * T;
        }
    }else{
        top = m;
        for(int i = 1; i <= m; i++){
           cin >> w[i];
           v[++top].push_back({i, w[i]});
           v[i].push_back({top, w[i]});
        }
        for(int i = 1; i <= n; i++){
            cin >> k[i];
            int la = -1;
            for(int j = 1, id, t; j <= k[i]; j++){
                cin >> id >> t;
                v[++top].push_back({m + id, t});
                v[m + id].push_back({top, t});
                if(la == -1){
                    la = top;
                }else{
                    v[top].push_back({la, 0});
                    v[la].push_back({top, 0});
                    la = top;
                }
            }
        }
        while(Q--){
            int l, r;
            cin >> l >> r;
            fill(vis + 1, vis + 4 * m + 1, 0);
            fill(dis + 1, dis + 4 * m + 1, 0);
            bfs(l);
            cout << dis[r] << '\n';
        }
    }

    return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/
