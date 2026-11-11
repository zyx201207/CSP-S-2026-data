#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=5e2+5;
const int M=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int test,n,m,d,q;
int w[M],k[N];
ll dist[N+M];
vector<pii> g[N+M];
void dijkstra(int s){
    for(int i=1;i<=n+m;i++)dist[i]=INF;
    dist[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(!q.empty()){
        pii tp=q.top();q.pop();
        int x=tp.second;
        ll y=tp.first;
        if(y>dist[x])continue;
        for(pii &it:g[x]){
            int u=it.second;
            ll v=it.first;
            if(dist[u]>dist[x]+v){
                dist[u]=dist[x]+v;
                q.push({dist[u],u});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>test>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a; ll t;
            cin>>a>>t;
            g[m+i].push_back({t,a});
            g[a].push_back({t,m+i});
        }
    }
    for(int i=1;i<=q;i++){
        int s,t;cin>>s>>t;
        dijkstra(s);
        cout<<dist[t]+w[s]+w[t]<<'\n';
    }
    return 0;
}
