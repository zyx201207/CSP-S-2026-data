#include <bits/stdc++.h>
using namespace std;
struct node{
    int id,time;
};
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005];
long long res = 1e18;
bool vis[500005];
vector <node> v[500005];
void cal(int cur,int des,long long cnt){
    if (cur == des){
        res = min(res,cnt);
        return;
    }
    for (int i = 0;i < v[cur].size();i++){
        node u = v[cur][i];
        for (int j = 1;j < k[u.id] + 1;j++){
            if (a[u.id][j] != cur && !vis[a[u.id][j]]){
                vis[a[u.id][j]] = 1;
                cal(a[u.id][j],des,cnt + t[u.id][j] + u.time);
            }
        }
    }
    return;
}
long long dist(int x,int y){
    res = 1e18;
    memset(vis,0,sizeof(vis));
    cal(x,y,0ll);
    return res + w[x] + w[y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i < m + 1;i++){
        cin >> w[i];
    }
    for (int i = 1;i < n + 1;i++){
        cin >> k[i];
        for (int j = 1;j < k[i] + 1;j++){
            cin >> a[i][j] >> t[i][j];
            v[a[i][j]].push_back({i,t[i][j]});
        }
    }
    while (q--){
        int x,y;
        cin >> x >> y;
        cout << dist(x,y) << '\n';
    }
    return 0;
}
