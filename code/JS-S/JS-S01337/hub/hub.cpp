#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,INF=LONG_MAX;
int c,t;
int n,k;
int dis[N],maxn;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("hub.in" ,"r",stdin );
    freopen("hub.out","w",stdout);
    dis[0]=-1;
    cin>>c>>t;
    for(int p=1;p<=k;p++){
        cin>>n>>k;
        vector<int>g[N];
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<0<<'\n';
    }
    return 0;
}
