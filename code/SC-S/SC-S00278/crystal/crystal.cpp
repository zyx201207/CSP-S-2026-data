#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N];
int n;ll m;
ll eng[N];
ll check(int cnt){
	ll ans=2e18;
	for(int i=cnt;i<=n;i++){
		ans=min(ans,eng[i]-(eng[i-cnt]+(i-cnt)*(a[i]-a[i-cnt])));
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)eng[i]=eng[i-1]+(i-1)*(a[i]-a[i-1]);
//	for(int i=1;i<=n;i++)cout<<eng[i]<<" ";
	int ans=0;
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		ll chk=check(mid);
		if(chk<=m){
			ans=mid;l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}