#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],ans,f[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=(1<<30)-1;
	for (int i=n-m+1;i<=n;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}