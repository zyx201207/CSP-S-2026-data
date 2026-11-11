#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[500010];
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0,ans=0;
	for(int i=1,j=0;i<=n;sum-=a[i],i++){
		while(j<=n && a[j]*(j-i+1)-sum<=m) j++,sum+=a[j];
		ans=max(ans,j-i);
	}
	cout<<ans;
	return 0;
} 
//Two-pointer everywhere 
//14:35 finish 