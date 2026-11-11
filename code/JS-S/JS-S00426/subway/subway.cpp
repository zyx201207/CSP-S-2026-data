#include<bits/stdc++.h>
using namespace std;
struct node{
    long long to,line;
};
struct que{
    long long x,line,change;
};
long long T;
vector <node> G[500005];
set <long long> lin[105];
long long w[500005];
long long ans = 1e18;
void bfs(long long u, long long v){
    queue <que> Q;
    for(auto x : lin[u]){
        Q.push({u,x,0});
    }
    while(!Q.empty()){
        que tp = Q.front(); Q.pop();
        if(tp.x == v){
            long long sum = w[u] + w[v] + (tp.change+1)*2*T;
            ans = min(sum,ans);
        }
        for(auto v : G[tp.x]){
            if(v.line != tp.line){
                Q.push({v.to,v.line,tp.change+1});
            }else{
                Q.push({v.to,v.line,tp.change});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q; cin >> c >> n >> m >> d >> q;
    for(long long i = 1; i <= m; i++) cin >> w[i];
    for(long long i = 1; i <= n; i++){
        long long k; cin >> k;
        long long la,lt; cin >> la >> lt;
        T = lt;
        for(long long j = 2; j <= k; j++){
            long long a,t; cin >> a >> t;
            G[la].push_back({a,i});
            lin[la].insert(i);

        }
    }
    if(c >= 12 && c <= 19){
        while(q--){
            long long u,v; cin >> u >> v;
            ans = 1e18;
            bfs(u,v);
            cout << ans << "\n";
        }
    }
    return 0;
}
/*
18:16
i've already sat(?) for more than 4 hours
*/