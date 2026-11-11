#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5,inf=1e18,mod=1e9+7;
ll n,m,ans,a[N],b[N];
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
