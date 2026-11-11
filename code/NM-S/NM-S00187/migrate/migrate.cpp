// 2/6 8pts
#include <iostream>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
int c, t, n, d, a[310], vis[310];
int dis[310][310], val[310][310];
struct qw
{
    int to, ne;
}ls[90010];
int head[310], idx = 0;
void add(int u, int v){
    ls[idx] = {v, head[u]};
    head[u] = idx;
    idx++;
}
void dfs(int u, int f, int cnt, int to){
    if(dis[f][u] > cnt){
        dis[f][u] = cnt;
        val[f][u] = 0;
    }
    else if(dis[f][u] == cnt){
        val[f][u]++;
    }
    for(int i = head[u]; i; i = ls[i].ne){
        int v = ls[i].to;
        if(to == 0 && v > u)
            continue;
        if(to == 1 && v < u)
            continue;
        cnt += llabs(a[u]-a[v]);
            dfs(v, f, cnt, to);
        cnt -= llabs(a[u] - a[v]);
    }
}
void clear(){
    memset(head, 0, sizeof head);
    idx = 1;
    memset(dis, 0x3f, sizeof dis);
    memset(val, 0, sizeof val);
}
void solve(){

    clear();
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(llabs(a[i]-a[j]) <= d && i != j){
                add(i, j);
                add(j, i);
            }
        }
    }

    for(int i = 1; i <= n; i++){

        dis[i][i] = 0;
        memset(vis, 0, sizeof vis);
        dfs(i, i, 0, 0);
        dfs(i, i, 0, 1);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(val[i][j] == 2)
                ans++;
        }
    }

    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
        solve();
}