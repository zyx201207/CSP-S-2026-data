#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=1;
	cin>>n>>m;
	vector<long long> a(n+1,0);
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(long long i=1;i<=n;i++)
	{
		a[i]=a[n-1]-a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long nm=m,j=1;
		for(j=1;j<=i&&nm>=a[i-j+1]-a[i];j++)
		{
			nm-=(a[i-j+1]-a[i]);
		}
		maxn=max(maxn,j-1);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
