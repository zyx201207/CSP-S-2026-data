#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,f[500005],ans=1,ans1=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+ans*(a[i]-a[i-1])-(a[i]-a[i-ans]);
        if(f[i]<=m){
            while(f[i]<=m&&ans<i){
                f[i]+=a[i]-a[i-ans];
                ans++;
            }
            if(f[i]>m)ans--,f[i]-=a[i]-a[i-ans];
        }
        //cout<<ans<<" "<<f[i]<<"\n";
    }
    cout<<ans;//<<" "<<f[n][1];
    return 0;
}
