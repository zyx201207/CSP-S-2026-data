#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int>g[20];
int vis[20];

void sol(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<n-k<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
       sol();
    }
}
