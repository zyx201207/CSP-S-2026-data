#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int A,AS;
	cin>>A>>AS;
	int sd=0;
	while(AS--)
	{
		sd++;
		long long n,m;
		long long ans=0;
		cin>>n>>m;
		if(n<4)
		{
			cout<<0<<'\n';
			continue;
		}
		vector<long long int>a(n+1,0);
		vector<long long int>b(n+1,n);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int r=1;
		for(int l=1;l<=n;l++)
		{
			while(r<=n)
			{	
				if(a[r]-a[l]>m)
				{
					b[l]=r-1;
					//cout<<r<<' '<<l<<"\n";
					break;
				}
				r++;
			}
		}
		//cout<<n;
		for(int i=1;i<=n-3;i++)
		{
			ans+=max(0LL,b[b[i]-1]-i-2);
			//cout<<max(0LL,b[b[i]-1]-i-2)<<' ';
		}
		cout<<ans<<'\n';
	}
	//cout<<sd;
	return 0;
}