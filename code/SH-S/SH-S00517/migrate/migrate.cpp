#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int x[2000005];
int minn=5e18,ans=0;
int u,v;
int n,d;
void dfs(int step,int sum)
{
	if (sum>minn)	return ;
	if (step==v)
	{
		if (minn==sum)
		{
			ans++;
		}
		if (sum<minn)
		{
			minn=sum;
			ans=1;
		}
		return ;
	}
	for (int i=step+1;i<=n;i++)
	{
		if (x[i]-x[step]<=d)	dfs(i,sum+1); 
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)	cin>>x[i];
		if (c>=11 && c<=12)
		{
			if (d/(x[2]-x[1])<=1)	cout<<0<<endl;
			else	cout<<max(n-(d/(x[2]-x[1])+d/(x[2]-x[1])-1),0ll)<<endl;
		}
		else
		{
			int anss=0;
			for (int i=1;i<=n;i++)
			{
				for (int j=i+1;j<=n;j++)
				{
					minn=5e18;
					ans=0;
					v=j;
					dfs(i,0);
					if (ans==2)
					{
//						cout<<i<<" "<<j<<" "<<minn<<endl;
						anss++;
					}
				}
			}
			cout<<anss<<endl;
		}
	}
	return 0;
}


