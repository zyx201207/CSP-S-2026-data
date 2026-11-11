#include <bits/stdc++.h>
using namespace std;

namespace{
const int N=5e5+5;
using ll=long long;

ll a[N],s[N];
void solve(){
    int n;ll m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,tmp=i;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)tmp=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-tmp+1);
    }
    cout<<ans<<'\n';
}
}


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}