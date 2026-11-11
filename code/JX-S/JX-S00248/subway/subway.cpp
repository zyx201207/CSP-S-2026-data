#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],cnt[N];
vector<pii> g[N];
int dist[N];
struct edge{
    int u;
    int v;
    int id;
}ll[N];
bool camp(edge x,edge y){
    return x.u<y.u;
}
void dij(int s){
    memset(dist,0x3f,sizeof(dist));
    priority_queue<pii,vector<pii> ,greater<pii> > qq;
    dist[s]=0;
    qq.push({dist[s],s});
    while(!qq.empty()){
        pii l=qq.top();
        qq.pop();
        int u=l.second;
        int sum=l.first;
        if(dist[u]<sum){
            continue;
        }
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first;
            int w=g[u][i].second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                qq.push({dist[v],v});
            }
        }
    }
    return ;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        vector<pii> q;
        for(int j=1;j<=k;j++){
            int a,t; cin>>a>>t;
            q.push_back({a,t});
        }
        for(int j=0;j<q.size();j++){
            int u=q[j].first;
            int w1=q[j].second;
            for(int l=0;l<q.size();l++){
                if(l==j){
                    continue;
                }
                int v=q[l].first;
                int w2=q[l].second;
                g[u].push_back({v,w1+w2});
                g[v].push_back({u,w1+w2});
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>ll[i].u>>ll[i].v;
        ll[i].id=i;
    }
    sort(ll+1,ll+q+1,camp);
    for(int i=1;i<=q;i++){
        if(ll[i].u!=ll[i-1].u){
            dij(ll[i].u);
        }
        cnt[ll[i].id]=dist[ll[i].v]+w[ll[i].v]+w[ll[i].u];
    }
    for(int i=1;i<=q;i++){
        cout<<cnt[i]<<'\n';
    }
    return 0;
}

