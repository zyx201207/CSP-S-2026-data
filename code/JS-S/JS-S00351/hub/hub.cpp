#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        vector <int> T[N];
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            T[u].push_back(v);
            T[v].push_back(u);
        }
        if(k==n) cout<<0<<'\n';
        else cout<<n-k<<'\n';
    }
    return 0;
}
