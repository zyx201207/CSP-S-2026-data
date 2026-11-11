#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;

ll c,t,n,k,dis[N],vis[N],s,maxn[N];
vector<ll>g[N];

void f(){
    memset(dis,127,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
    q.push({0,s});
    while(!q.empty()){
        pair<ll,ll>tp=q.top();
        ll u=tp.second;
        q.pop();
        for(auto v:g[u]){
            if(dis[u]+1>dis[v]){
                dis[v]=dis[u]+1;
                q.push({dis[v],v});
            }
        }
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            s=i;
            f();
            for(int j=1;j<=n;j++){
                maxn[i]=max(maxn[i],dis[j]);
            }
        }
        sort(maxn+1,maxn+n+1);
        cout<<maxn[k]<<"\n";
    }
    return 0;
}
