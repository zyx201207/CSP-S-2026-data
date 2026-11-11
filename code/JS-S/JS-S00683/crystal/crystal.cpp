#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN=500010;
int n,m,a[maxN],ans=1,l=1,r=1;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    while(r<=n){
        int need=(r-l+1)*(a[r+1]-a[r]);
        while(m-need<0) m+=a[r+1]-a[l],l++;
        m-=need,r++,ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}