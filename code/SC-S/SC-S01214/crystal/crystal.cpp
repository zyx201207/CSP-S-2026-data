#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500006],s[500006];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid=0;
        while(l<r){
            mid=(l+r)/2;
            int t=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
            if(t>m) l=mid+1;
            else r=mid;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0; 
}