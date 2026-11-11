#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],s[500005],ans=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        ll l=1,r=i,res=0;
        while(l<=r){
            ll mid=(l+r)>>1,val=(i-mid+1)*a[i]-(s[i]-s[mid-1]);
            if(m>=val) res=mid,r=mid-1;
            else l=mid+1;
        }
        //cout<<res<<'\n';
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
