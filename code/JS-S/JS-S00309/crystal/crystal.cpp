#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m,ans=1;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1,t=0;
    while(r+1<=n){
        r++;
        t+=((a[r]-a[r-1])*(r-l));
        while(t>m){
            t-=(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
