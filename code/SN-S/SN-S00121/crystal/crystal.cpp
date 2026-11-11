#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int ans=0;
	for (int i=n;i>=1;i--){
		int sum=s[i]+m;
		if (m>=(sum%i+i)%i)
			sum-=(sum%i+i)%i;
		if (a[i]>sum/i) continue;
		ans=max(ans,i-(int)(sum%i!=0));
	}
	cout<<ans;
	return 0;
}
