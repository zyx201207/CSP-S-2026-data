#include<bits/stdc++.h> 
using namespace std;
long long a[500005],m;
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sum=0;int maxx=-1;
	for(int i=1;i<=n;++i)
	{
		sum=0;int j=0;
		for(j=i-1;j>=1&&sum<m;--j)
		{
			sum+=a[i]-a[j];
		}
		if(sum==m)
		{
			maxx=max(i-j,maxx);
		}
		else
		{
			maxx=max(i-j-1,maxx);
		}
	}
	cout<<maxx;
	return 0;
}