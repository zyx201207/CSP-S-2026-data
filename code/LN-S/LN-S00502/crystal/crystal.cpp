#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500050], ans, b[500050], p, q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(long long i=1;i<=n-1;i++)
	{
		p=0;
		q=0;
		for(long long j=i;j<=n-1;j++)
		{
			q+=1;
			p+=b[j]*q;
			if(p>m) break;
		}
		ans=max(ans,q);
	}
	cout<<ans;
	return 0;
}
