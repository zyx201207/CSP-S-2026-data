#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int M = 5e5+10;
const int N = 510;
int c,n,m,d2,q;
int w[M],t[N][M];
vector<pii> g[M];
int flag[M],d[M];
void dijkstra(int root)
{
    memset(flag,0,sizeof(flag));
    memset(d,0x3f,sizeof(d));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    d[root] = 0;
    q.push({d[root],root});
    flag[root] = 1;
    while(!q.empty()){
        auto tt = q.top();
        q.pop();
        int u = tt.second;
        if(!flag[u]) continue;
        //cout<<u<<"\n";
        for(auto t:g[u]){
            int v = t.first;
            int w = t.second;
            //cout<<"    "<<v<<" "<<w<<"\n";
            if(d[u]+w<d[v]){
                d[v] = d[u]+w;
                if(!flag[v]){
                    flag[v] = 1;
                    q.push({d[v],v});
                }
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d2,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k; scanf("%lld",&k);
        int v[k+10];
        memset(v,0,sizeof(v));
        for(int j=1;j<=k;j++){
            scanf("%lld",&v[j]);
            scanf("%lld",&t[i][v[j]]);
            for(int l = j-1;l>=1;l--){
                //cout<<j<<" "<<k<<" "<<t[i][j]+t[i][k]<<"\n";
                g[v[j]].push_back({v[l],t[i][v[j]]+t[i][v[l]]});
                g[v[l]].push_back({v[j],t[i][v[j]]+t[i][v[l]]});
            }
        }
    }
    /*for(int i=1;i<=m;i++){
        for(auto j:g[i]) {
            cout<<i<<" "<<j.first<<" "<<j.second<<"\n";
        }
    }*/
    for(int i=1;i<=q;i++){
        int s,t;
        scanf("%lld %lld",&s,&t);
        dijkstra(s);
        printf("%lld\n",d[t]+w[s]+w[t]);
    }

    return 0;
}
