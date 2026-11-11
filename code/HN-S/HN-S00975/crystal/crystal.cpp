#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int x=1;x<=n;x++)cin>>a[x];
    sort(a+1,a+n+1);
    int l=1,ans=1,s=0;
    for(int x=2;x<=n;x++){
        s+=(a[x]-a[x-1])*(x-l);
        while(l<x&&s>m){
            s-=(a[x]-a[l]);
            l++;
        }
        ans=max(ans,x-l+1);
        //cout<<x<<' '<<l<<'\n';
    }
    cout<<ans<<'\n';
}
/*

*/