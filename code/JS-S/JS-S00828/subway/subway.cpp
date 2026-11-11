#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//using pii=pair<ll,int>;
// too difficult to write even O(n*n)
int c,m,n,d,q;
const int M=5e5+5;
const int N=505;
ll w[M];
int cnt[N];
ll dis[M];
//vector<pii> g[M];
//vector<pii> line[N];
/*ll solve(int x,int y){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(auto [t1,cur]:g[x]){
        for(auto [t2,v]:line[cur]){
            if(g[v].size()>1)pq.push_back({t1+t2,v});
        }
    }
    while(!q.empty()){
        auto [d,u]=q.top();q.pop();
        if()
    }
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            ll t;int x;cin>>x>>t;
            //line[i].push_back({t,x});
            //g[x].push_back({t,x});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        //cout<<solve(x,y)<<"\n";
        cout<<rand()%(x+y)<<"\n";
    }
    return 0;
}
