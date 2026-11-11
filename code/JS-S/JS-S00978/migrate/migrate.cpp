#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int a[2000020];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        int x;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>d+1&&a[j]-a[i]<2*d)ans++;
                else if(a[j]-a[i]==d+1&&(a[j]-a[i])%2!=0)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
