#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5E2 + 5;
const int MAXM = 5E5 + 5;
const int MAXD = 2E1 + 5;

long long gate[MAXM];

struct Node{
    int u;
    long long w;
};

vector<Node> g[MAXM];

long long mp[MAXN][MAXN];

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 4
*/

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int n, m, d, q;
    cin >> n >> n >> m >> d >> q;

    for(int i = 1; i <= m; i++ ) cin >> gate[i];
    for(int i = 1; i <= n; i++ ){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++ ){
            int a;
            long long t;
            cin >> a >> t;
            g[a].push_back({i, t});
        }
    }

    for(int x = 1; x <= m; x++ ){

        for(Node i : g[x]){
            for(Node j : g[x]){
                if(i.u == j.u) continue;
                if(mp[i.u][j.u] == 0 || i.w + j.w < mp[i.u][j.u]) mp[i.u][j.u] = i.w + j.w;
            }
        }

    }

    for(int k = 1; k <= n; k++ ){
        for(int i = 1; i <= n; i++ ){
            for(int j = 1; j <= n; j++ ){
                if(i == j) continue;
                if(mp[i][k] && mp[k][j] && (mp[i][j] == 0 || mp[i][k] + mp[k][j] < mp[i][j])) mp[i][j] = mp[i][k] + mp[k][j];
            }
        }
    }

    while(q--){

        int s, t;
        cin >> s >> t;

        long long ans = (long long)1E18;
        for(Node i : g[s]){
            for(Node j : g[t]){
                if(mp[i.u][j.u] + i.w + j.w < ans) ans = mp[i.u][j.u] + i.w + j.w;
            }
        }

        cout << ans + gate[s] + gate[t] << '\n';

    }

    return 0;
}

