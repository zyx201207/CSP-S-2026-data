#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],sum[500005],n,m;
bool check(int now){
	int mi=2e18;
	for(int i=1;i<=n-now+1;i++) mi=min(a[i+now-1]*now-sum[i+now-1]+sum[i-1],mi);
	if(mi<=m) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=n,ans=0;
	while(r>=l){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

