#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int ans=0;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    ans=1;
    while(t--){
        cin>>t;
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
        }
        cout<<ans<<"\n";
        ans++;
    }
    return 0;
}
