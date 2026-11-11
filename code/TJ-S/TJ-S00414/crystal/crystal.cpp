#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005]={},q[500005]={};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin >>n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    q[0]=0;
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        ll l=1,r=i,mid=(l+r)/2;
        while(r-l>1){
            mid=(l+r)/2;
            if(a[i]*(i-mid+1)-q[i]+q[mid-1]<=m)r=mid;
            else l=mid;
        }
        if(a[i]*(i-mid+1)-q[i]+q[l-1]<=m)r=l;
        ans=max(ans,i-r+1);
    }
    cout << ans << '\n';
    return 0;
}