#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    int a[n+2];
    char c[n+2];
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        if(a[l]==a[r])ans+=a[l]*(c[l]!=c[r]),l++,r--;
        else if(a[l]>a[r])a[l]-=a[r],ans+=a[r]*(c[l]!=c[r]),r--;
        else if(a[l]<a[r])a[r]-=a[l],ans+=a[l]*(c[l]!=c[r]),l++;
    }
    cout<<ans;
}
