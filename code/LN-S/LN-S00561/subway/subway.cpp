#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=6e5+10;
int c,n,m,s,q,T[N],idx,d[N],flag[N];
vector<PII> g[N];
void init(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}
void dijkstra(int root){
    for(int i=1;i<=m;i++) d[i]=1e18,flag[i]=0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,root});
    d[root]=0;
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(flag[u]) continue;
        flag[u]=1;
        for(auto e:g[u]){
            int v=e.first,w=e.second;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
signed main(){
    init();
    //freopen("subway4.in","r",stdin);
    //freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>s>>q;
    idx=n;
    for(int i=1;i<=m;i++){
        cin>>T[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        ++m;
        while(k--){
            int u,w;
            cin>>u>>w;
            g[u].push_back({m,w});
            g[m].push_back({u,w});
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        dijkstra(u);
        cout<<d[v]+T[u]+T[v]<<"\n";
    }
    return 0;
}
