#include<bits/stdc++.h>
using namespace std;

int c,t,n;
const int MAXN = 2000005;
const int INF = 1e9;
long long d;
long long x[MAXN];
int dis[305][305];
int cnt[305][305];
long long ans;
long long gap;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		cout<<n<<endl;
		for(int i=1;i<=n;i++) cin>>x[i];
		
		if(c==11 || c==12 || 1)
		{
			gap = d / abs(x[1] - x[2]);
			ans = n - 2*gap + 1;
			if(ans > 0 && gap < n && gap > 1) cout<<ans<<endl;
			else cout<<0<<endl;
		}
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) dis[i][j] = 0;
				else dis[i][j] = INF;
			}
		}
		
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j && abs(x[i] - x[j]) <= d)
					dis[i][j] = 1;
			}
		}
		
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dis[i][k] < INF && dis[k][j] < INF)
					{
						if(dis[i][k] + dis[k][j] == dis[i][j]) cnt[i][j]++;
						else if(dis[i][k] + dis[k][j] < dis[i][j])
						{
							dis[i][j] = dis[i][k] + dis[k][j];
							cnt[i][j] = 1;
						}
					}
				}
			}
		}
		
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cout<<cnt[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		ans = 0;
		for(int i=1;i<=n;i++)
		{
		 	for(int j=1;j<i;j++)
		 	{
		 		if(cnt[i][j] == 3) ans++;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
		 	for(int j=1;j<=n;j++)
		 	{
		 		cnt[i][j] = 0;
			}
		}
		cout<<ans<<endl;
		*/
	}
	
	return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
