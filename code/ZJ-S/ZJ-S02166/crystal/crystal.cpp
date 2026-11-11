#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N];
ll s0[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s0[i]=s0[i-1]+a[i];
	
	for(int i=n;i>=1;i--){
		ll l=1,mid,r=i;
		while(l+1<r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-(s0[i]-s0[mid-1])<=m) r=mid;
			else l=mid;
		}
		if(a[i]*(i-l+1)-(s0[i]-s0[l-1])<=m) r=l;
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
