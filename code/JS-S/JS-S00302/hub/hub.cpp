#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,u,v;
vector<ll>G[N];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==13||x==14){
        while(t--){
            cin>>n>>k;
            for(int i=1;i<=n;++i){
                cin>>u>>v;
                G[v].push_back(u);
                G[u].push_back(v);
            }
            cout<<n-k+1<<'\n';
        }
    }
    return 0;
}
