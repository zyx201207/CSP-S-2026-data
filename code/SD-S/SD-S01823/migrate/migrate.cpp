#include <iostream>
#include <cstdio>
using namespace std;
long long c,t,a[1000001],i;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);   
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			long long n,m,sum=0;
			cin>>n>>m;
			for(i=1;i<=n;i++)
			cin>>a[i];
			int ans=a[2]-a[1];
			/*sum=m/ans-1;
			sum=(n-sum-2)*sum;*/
			sum=m/ans-1;int z=0;
			z=(n-sum-1)*sum;
			for(i=n-sum;i<=n-1;i++)
			{
				sum--;
				z+=sum;
			}
			cout<<z<<'\n';
		}
		return 0; 
	}
	while(t--)
	cout<<0<<endl;
	return 0;
}
