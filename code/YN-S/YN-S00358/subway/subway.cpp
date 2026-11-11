#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=510,M=5e5+10;
constexpr ll inf=1e18;
int c,n,m,d,q;
vector<pair<int,ll>>g[M*2+N];
struct cmp{
    bool operator()(const pair<int,ll>&x,const pair<int,ll>&y){
        return x.second>y.second;
    }
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1,w;i<=m;i++){
        cin>>w;
        g[i].emplace_back(i+m,w);
        g[i+m].emplace_back(i,w);
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            g[m*2+i].emplace_back(a,t);
            g[a].emplace_back(m*2+i,t);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        vector<ll>dis(m*2+n+10,inf);
        priority_queue<pair<int,ll>,vector<pair<int,ll>>,cmp>q;
        dis[m+x]=0;
        q.emplace(m+x,0);
        while(!q.empty()){
            int u=q.top().first,dn=q.top().second;
            q.pop();
            for(pair<int,ll>i:g[u]){
                int v=i.first;
                ll w=i.second;
                if(dis[v]>dn+w){
                    dis[v]=dn+w;
                    q.emplace(v,dis[v]);
                }
            }
        }
        cout<<dis[m+y]<<'\n';
    }
    return 0;
}
