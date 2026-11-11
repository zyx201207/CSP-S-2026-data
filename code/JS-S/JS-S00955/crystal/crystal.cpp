#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],pre[500005],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<=n&&a[j]*(j-i+1)-(pre[j]-pre[i-1])<=m) j++;
		ans=max(ans,j-i);
	}
	cout<<ans<<"\n";
	return 0;
}
