#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r",stdin)
    freopen("migrate.out","w",stdout)
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=t;i++){
            int n,d;
            cin>>n>>d;
            int a[n-1];
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(a[i]-a[j]<=d){
                       ans+=1;
                    }
                }
            }
            cout<<ans<<"\n";
        }
        continue;
    }

    return 0;
}
