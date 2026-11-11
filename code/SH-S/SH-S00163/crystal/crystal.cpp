#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+9;
ll n,m,a[N],s[N];
bool ok(ll x){
    for(ll i=x;i<=n;i++)
	if(a[i]*x-s[i]+s[i-x]<=m)
	    return 1;
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
	cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
	s[i]=s[i-1]+a[i];
    ll l=2,r=n,mid,ans=1;
    while(l<=r){
	mid=(l+r)/2;
	if(ok(mid)) ans=mid,l=mid+1;
	else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
