#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
struct edge{
    ll to,dis;
    bool operator<(const edge &x)const &{
        return x.dis<dis;
    }
};
vector<edge>g[N];
ll c,n,m,d,q,k;
ll w[N],a[N],t[N];
ll f[N],vis[N];
void dijkstra(int st){
    priority_queue<edge>q;
    q.push(edge{st,0});
    memset(f,0x3f3f3f3f,sizeof f);
    memset(vis,0,sizeof vis);
    f[st] = 0;
    while(!q.empty()){
        edge e = q.top();
        q.pop();
        int u = e.to;
        for(auto x:g[u]){
            if(!vis[x.to]){
                if(f[x.to]>f[u]+x.dis){
                    f[x.to] = f[u]+x.dis;
                    q.emplace(edge{x.to,f[x.to]});
                    vis[x.to] = 1;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            for(int p=1;p<j;p++){
                ll l = t[j]+t[p];
                g[a[j]].push_back(edge{a[p],l});
                g[a[p]].push_back(edge{a[j],l});
            }
        }
    }
    while(q--){
        int st,ed;
        cin>>st>>ed;
        dijkstra(st);
        cout<<w[st]+w[ed]+f[ed]<<endl;
    }
}
