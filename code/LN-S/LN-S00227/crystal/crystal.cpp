#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans,a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1,j=1;i<=n && j<=n;)
	{
		while((s+(j-i+1)*(a[j+1]-a[j]))<=m && j<n)
		{
			s=(s+(j-i+1)*(a[j+1]-a[j]));
			j++;
			//cout<<j;
		}
		ans=max(ans,j-i+1);
		s-=(a[j]-a[i]);
		i++;
	}
	cout<<ans;
	return 0;
}
