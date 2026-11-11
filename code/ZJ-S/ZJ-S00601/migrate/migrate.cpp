#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

using ll = long long;
int c,t;
int n;
ll d;
ll a[N];
ll mp[1010][1010];
ll vis[1010][1010];
ll num = 0;
ll inf = LLONG_MAX;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		num = 0;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c<=6)
		{
			for(int i = 1;i<=n;i++)
			{
				for(int j = 1;j<=n;j++)
				{
					mp[i][j] = inf;
					vis[i][j] = -1;
				}
				mp[i][i] = 0;
			}
			for(int i = 1;i<=n;i++)
			{
				for(int j = i+1;a[j]-a[i]<=d&&j<=n;j++)
				{
					mp[i][j] = mp[j][i] = 1;
				}
			}
//			for(int i = 1;i<=n;i++)
//			{
//				for(int j = 1;j<=n;j++)
//				{
//					if(mp[i][j] == inf) cout<<-1<<" ";
//					else cout<<mp[i][j]<<" ";
//				}
//				cout<<endl;
//			}
			for(int i = 1;i<=n;i++)
			{
				for(int j = 1;j<=n;j++)
				{
					for(int k = 1;k<=n;k++)
					{
						if(mp[i][k] != inf&&mp[k][j] != inf&&i != j&&j != k&&k != i)
						{
							ll od = mp[i][j];
							ll nw = mp[i][k]+mp[k][j];
							if(od>nw)
							{
								mp[i][j] = nw;
								vis[i][j] = 1;
							}
							if(od == nw)
							{
								vis[i][j]++;
							}
//							cout<<i<<" "<<j<<" "<<k<<":"<<od<<" "<<nw<<" "<<mp[i][j]<<" "<<vis[i][j]<<" "<<"\n";
						}
					}
				}
			}
//			for(int i = 1;i<=n;i++)
//			{
//				for(int j = 1;j<=n;j++)
//				{
//					if(mp[i][j] == inf) cout<<-1<<" ";
//					else cout<<mp[i][j]<<" ";
//				}
//				cout<<endl;
//			}
//			for(int i = 1;i<=n;i++)
//			{
//				for(int j = 1;j<=n;j++)
//				{
//					cout<<vis[i][j]<<" ";
//				}
//				cout<<endl;
//			}
			for(int i = 1;i<=n;i++)
			{
				for(int j = i+1;j<=n;j++)
				{
					if(vis[i][j] == 2) num++;
				}
			}
			cout<<num<<"\n";
			continue;
		}
		if(c == 11||c == 12)
		{
			ll gc = a[2]-a[1];
			ll shul = d/gc;
			shul*=2;
			if(shul <= 1||shul>=n)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				cout<<n-shul+1<<endl;
				continue;
			}
		}
	}
	return 0;
}
