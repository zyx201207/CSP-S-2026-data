#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    int a[n+2];
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int x=1;x<=n;x++){
        int now=x,t=m;
        while(t&&now){
            if(t>=a[x]-a[now])t-=(a[x]-a[now]),now--;
            else break;
        }
        ans=max(ans,x-now);
    }
    cout<<ans;
}
