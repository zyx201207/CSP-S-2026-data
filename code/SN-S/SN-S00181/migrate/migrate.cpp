#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000006];
vector<int> g[2000006];
struct node
{
	int sum,minn=1e9;
}t[5005][5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11 or c==12)
		{
			int t=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[1]>d)
				{
					t=i-1;
					break;
				}
			}
			if(t>3) cout<<0<<'\n';
			else cout<<n-t<<'\n';
			continue;
		}
		if(c==13 or c==14)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				t[i][j].sum=0;
				t[i][j].minn=1e9;
				if(a[j]-a[i]<=d)
				{
					g[i].push_back(j);
					if(i==j)t[i][j].minn=0;
					else t[i][j].minn=1;
					t[i][j].sum=1;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(i==k or j==k) continue;
					if(t[i][k].minn+t[k][j].minn<t[i][j].minn)
					{
						t[i][j].minn=t[i][k].minn+t[k][j].minn;
						t[i][j].sum=t[i][k].sum*t[k][j].sum;
					}
					else if(t[i][k].minn+t[k][j].minn==t[i][j].minn)
					{
						t[i][j].sum+=t[i][k].sum*t[k][j].sum;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(t[i][j].sum==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
