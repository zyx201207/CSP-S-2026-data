#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll m,n,ans;
ll a[N],cf[N];
ll l1,r1;
void deal(ll l,ll r,ll cfs){
	while(l<=r and l>=1){
		if(cfs+cf[r]-cf[l]<=m){
			cfs+=cf[r]-cf[l];
			ll e=ans;
			ans=max(ans,r-l+1);
			if(e!=ans){
				l1=l;
				r1=r;
			}
			l--;
		}
		else{
			cfs-=(r-l)*(cf[r]-cf[r-1]);
			r--;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cf[i]=a[i]-a[i-1]+cf[i-1];
	}
	sort(cf+1,cf+n+1);
	ans=1;
	deal(n,n,0);
	cout<<ans;
	return 0;
}