#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d,q;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		q=a[n]-a[n-1];
		d/=q;
		if(n-2*d+1<=0||d==0)
		{
			cout<<0<<'\n';
		}
		else
		{
			cout<<n-2*d+1<<'\n';
		}
	}
	return 0;
}
