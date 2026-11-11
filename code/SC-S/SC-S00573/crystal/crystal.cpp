#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],d[500005],su[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++){
		d[i]=a[i]-a[i-1];
		su[i]=su[i-1]+d[i];
	}
	ll l=1,sum=0,ans=-10;
	for(int r = 1; r <= n; r++){
		sum+=d[r]*(r-l);
		while(sum>m&&l<=r){
			l++;
			sum-=a[r]-a[l];
		}
		//cout<<l<<' '<<r<<' '<<sum<<'\n';
		if(sum<=m){
			ans=max(ans,r-l+1);
		}
	}
//	while(l<=r&&r<=n){
//		if(cnt>20) break;
//		while(sum>m&&l<=r){
//			l++;
//			sum-=su[r]-su[l-1];
//		}
//		if(sum<=m){
//			ans=max(ans,r-l+1);
//			if(r==n) break;
//		} 
//		cout<<l<<' '<<r<<' '<<sum<<'\n';
//		while(sum<=m&&r<=n){
//			r++;
//			sum+=d[r]*(r-l+1);
//		}
//		cnt++;
//	}
	cout<<ans;
	return 0;
}