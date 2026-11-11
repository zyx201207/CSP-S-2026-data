#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005,inf=2e18;
int n,m,ans,a[N];
bool check(int len){
	int cost=0;
	for(int i=1;i<=len;i++)cost=cost+a[len]-a[i];
	if(cost<=m)return 1;
	for(int i=len+1;i<=n;i++){
		cost=cost+(a[i]-a[i-1])*len-(a[i]-a[i-len]);
		if(cost<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
