#include<bits/stdc++.h>
using namespace std;
long long int c,w[500005],k[505],a[505][500005],t,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long n,d,l,q;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		l=x[2]-x[1];
		if(d>=x[n]-x[1])
		{
			cout<<0;
			break;
		}
		q=d/l;
		if(q==1)
		{
			cout<<0;
			break;
		}
		else
		{
			if(d%l==0)
			{
				cout<<0;
				break;
			}
			else
			{
				cout<<2;
				break;
			}
		}
	}
	return 0;
}
