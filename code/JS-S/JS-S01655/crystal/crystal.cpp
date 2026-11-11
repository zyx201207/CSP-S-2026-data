#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010110],ans=0,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=2,req=0;
    while(l<=r&&r<=n){
        req+=(r-l)*(a[r]-a[r-1]);
        if(req<=m){ans=max(ans,(r-l+1));}
        else{
            req-=a[r]-a[l];
            l++;
            ans=max(ans,(r-l+1));
        }r++;
    }
    cout<<ans;
    return 0;

}/*










inclusteam xiaoheshuangpin
dcciyiyz

2026/10/31 14:30
*/
