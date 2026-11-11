#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,k,T,a[500005];
//prority_queue;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        vector<ll> g[1000006];
        cin>>n>>k;
        for(int i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n==k){
            cout<<0<<'\n';
            continue;
        }
    }

    return 0;
}


