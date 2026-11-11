#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

long long int c,n,m,d,q,begining,ending,ans;
long long int w[N],k[505];
pair<long long int,long long int> p[505][505];

long long int fun( long long int x, long long int y, long long int l)
{
	
	if(y == ending)
	{
		cout<<p[x][y].second<<endl;
		return p[x][y].second;
	}
	for(int j = 1; j <= k[l]; j++)
	{
		if(j == ending)
		{
			cout<<p[x][j].second<<endl;
			return p[x][j].second;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k[i]; j++)
		{
			if(p[i][j].first == p[x][y].first&&(i!=x||j!=y))
			{
				return p[x][y].second*2+p[i][j].second+fun(i,j,k[i]);
			}
		}
		cout<<endl;
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			cin>>p[i][j].first>>p[i][j].second;
		}
	}
	while(q--)
	{
		ans=0;
		cin >> begining >> ending;
		for(long long int i = 1; i <= n; i++)
		{
			for(long long int j = 1; j <= k[i]; j++)
			{
				if(p[i][j].first == begining)
				{
					ans = max( ans, fun(i,j,k[i]));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
