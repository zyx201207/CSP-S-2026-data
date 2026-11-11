#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum=0,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,ans=1;
	for(int r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		if(sum<=m)ans=max(ans,r-l+1);
		while(sum>m)sum-=(a[r]-a[l]),l++;
	}
	cout<<ans;
	return 0;
}
