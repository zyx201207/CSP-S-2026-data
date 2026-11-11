#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int a[2000005];

main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]-a[j]<=d)continue;
                if(a[i]+d>=a[i+2]&&a[i]+d<a[i+3])ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
