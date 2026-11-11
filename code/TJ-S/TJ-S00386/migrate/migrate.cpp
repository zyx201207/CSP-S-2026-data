#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
ll c,T,n,d,v[N],mn=1e18,mni=0,ans=0,sl=0;
ll dfs(ll l,ll r,ll sum) {
	if(l>=r) {
		if(sum<mn) {
			mn=sum;
			mni=1;
		} else if(sum==mn)mni++;
		return 0;
	}
	for(int i=l+1; i<=r; i++) {
		if(v[i]-v[l] <= d) {
			ll cnt=0;
			
			cnt=dfs(i,r,sum+1ll);
		}
		else break;
	}
	return 0;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {

		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>v[i];
		ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				mn=1e18;
				mni=0;
				sl=i;
				dfs(i,j,0);
				if(mni==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
