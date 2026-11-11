#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,dd,q,a[500005],d[505],ad[505][505];//n=metro line,m=metro station
bool f[505];
struct node{
    int v,d;
};
vector<node>e[500505],se[505];
struct qn{
    int a;
};
bool operator<(qn x,qn y){
    return d[x.a]>d[y.a];
}
bool operator==(qn x,qn y){
    return d[x.a]==d[y.a];
}
bool operator>(qn x,qn y){
    return d[x.a]<d[y.a];
}
void dijkstra(int s){
    memset(f,0,sizeof(f));
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    priority_queue<qn>q;
    q.push({s});
    while(!q.empty()){
        int tmp=q.top().a;
        q.pop();
        if(f[tmp]) continue;
        f[tmp]=1;
        for(auto x:se[tmp])
            if(!f[x.v]){
                d[x.v]=min(d[x.v],d[tmp]+x.d);
                q.push({x.v});
            }
    }
    for(int i=1;i<=n;i++) ad[s][i]=d[i];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int v,d;
            cin>>v>>d;
            e[m+i].push_back({v,d});
            e[v].push_back({m+i,d});
        }
    }
    for(int i=1;i<=n;i++)
        for(auto x:e[i+m])
            for(auto y:e[x.v])
                if(y.v-m!=i){
                    se[i].push_back({y.v-m,x.d+y.d});
                    se[y.v-m].push_back({i,x.d+y.d});
                }
    for(int i=1;i<=n;i++) dijkstra(i);
    while(q--){
        int u,v,ans=1e18;
        cin>>u>>v;
        for(auto x:e[u])
            for(auto y:e[v]) ans=min(ans,ad[x.v-m][y.v-m]+x.d+y.d);
        cout<<ans+a[u]+a[v]<<"\n";
    }
    return 0;
}
