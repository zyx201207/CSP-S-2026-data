#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+5;
ll n,m,a[N],b[N],now,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		a[i]=b[n-i+1];
	for(ll l=1,r=0;l<=n;l++){
		now-=(r-l+1)*(a[l-1]-a[l]);
		while(r<n&&now+a[l]-a[r+1]<=m){
			r++;
			now+=a[l]-a[r];
		}
		ans=max(ans,r-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}