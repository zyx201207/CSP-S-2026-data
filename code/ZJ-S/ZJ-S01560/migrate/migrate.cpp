#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
vector<long long> init;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>d;
		init.resize(n+5);
		init[0]=0;
		for (int i=1;i<=n;i++)
		{
			cin>>init[i];
		}
		if (init[3]-init[2]==init[2]-init[1])
		{
			long long d1=init[3]-init[2];
			long long x=d/d1;
			if (x<2)
			{
				cout<<"0"<<endl;
			}
			else
			{
				x++;
				int ans=0;
				for (int i=1;2*i+i<=x;i++)
				{
					ans+=(n-(2*i+i));
				}
				cout<<ans<<endl;
			}
		}
		else
		{
			vector<vector<int> > z;
			vector<vector<int> >fg;
			z.resize(n+5);
			fg.resize(n+5);
			for (int i=1;i<=n;i++)
			{
				fg[i-1].resize(n+5);
				fill(fg[i-1].begin(),fg[i-1].end(),0);
			}
			z[0].resize(n+5);
			fill(z[0].begin(),z[0].end(),0x3fffffff);
			for (int i=0;i<n-1;i++)
			{
				z[i+1].resize(n+5);
				fill(z[i+1].begin(),z[i+1].end(),0x3fffffff);
				z[i][i]=0;
				z[i+1][i]=z[i][i+1]=init[i+1]-init[i];
			}
			for (int k=0;k<n;k++)
			{
				for (int i=0;i<n;i++)
				{
					for (int j=0;j<n;j++)
					{
						if (i!=j&&j!=k&&k!=i)
						{
							z[i][j]=min(z[i][j],z[i][k]+z[k][j]);
						}
					}
				}
			}
			for (int k=0;k<n;k++)
			{
				for (int i=0;i<n;i++)
				{
					for (int j=0;j<n;j++)
					{
						if (i!=j&&j!=k&&k!=i)
						{
							if (z[i][j]==z[i][k]+z[k][j])
							{
								fg[i][j]++;
							}
						}
					}
				}
			}
			int cnt=0;
			for (int i=0;i<n;i++)
			{
				for (int j=i;j<n;j++)
				{
					if (fg[i][j]==2)
					{
						cnt++;
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
