#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1,num,a[500005],s[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=1,r=i,mid;
        while(l<r){
            mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
