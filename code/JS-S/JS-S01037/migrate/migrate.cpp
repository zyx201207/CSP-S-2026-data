#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int INF = 1061109567;
int t;
long long a[N];
int d[N],n,m,cnt[N];
void dijk(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(q.size()){
        auto tmp = q.top();
        int w = tmp.first,u = tmp.second;
        //cerr<< u << ' ' <<w << endl;
        q.pop();
        if(w > d[u]) continue;
        if(d[u] == w) cnt[u] ++;
        if(d[u] > w){
            cnt[u] = 1;
            d[u] = w;
        }
        for(int v = 1;v <= n;v ++){
            if(abs(a[v]-a[u]) <= m && v != u){
                q.push({w+1,v});
            }
        }
    }
}
void solve(){
    memset(d,0x3f,sizeof d);
    cin >> n >> m;
    // cerr << d[1] << endl;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    // d[1] = 0;
    dijk(1);
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        // if (i == u) continue;
        // cerr << cnt[i] << endl;
        if(cnt[i] == 2) ans ++;
    }
    cout << ans << "\n";
    // cerr << endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // // freopen("migraterr.out","w",stderr);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t >> t;
    while(t --) solve();
}
