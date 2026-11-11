#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],rd[2000005],cd[2000005],sum;
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					rd[j]++;
					cd[i]++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(cd[i]==cd[i+1]&&cd[i]!=cd[i-1])
			{
				sum++;
			}
			if(rd[i]==rd[i+1]&&rd[i]!=rd[i-1])
			{
				sum++;
			}
		}
		if(sum%2!=0)
			cout<<sum/2;
		else
			cout<<sum/2-1;
	}
	return 0;
}
