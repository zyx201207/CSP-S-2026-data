#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,nm=0;
    int ans=1;
    for(int i=1;i<=n;i++){
        nm=(i-l)*(a[i]-a[i-1])+nm;
        while(nm>m) nm-=a[i]-a[l],++l;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
