#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, ans, x, y;
int w[N], k[505], a[505][505], t[505][505];
int tme[N];
struct node{
    int to, line;
};
vector<node> Q[N];
queue<node> Qu;
int rem = INT_MAX;
void bfs(int lz){
    Qu.push({x, 0});
    while(!Qu.empty()){
        node u = Qu.front();
        Qu.pop();
        if(Q[u.to].size() == 0)continue;
        int nl = (lz == 0 ? 0 : u.line);        
        for(auto v : Q[u.to]){
            Qu.push(v);
            if(v.to == y && tme[v.to] >= tme[u.to]){
                rem = min(rem, t[v.line][v.to]);
            }
            if(v.line != nl){
                if(!nl)nl = v.line;
                tme[v.to] = min(tme[v.to], tme[u.to] + t[nl][u.to] + t[v.line][u.to]);
            }
            else tme[v.to] = min(tme[v.to], tme[u.to]);
        }
        lz = u.to;
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    } 
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            cin >> a[i][j] >> t[i][j];
            Q[a[i][j - 1]].push_back({a[i][j], i});
        }
    }
    while(q--){
        cin >> x >> y;
        ans += w[x] + w[y];
        for(int i = 1; i <= m; i++){
            tme[i] = INT_MAX;
        }
        bfs(0);
        cout << tme[y] + rem << "\n";
    }
    return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/