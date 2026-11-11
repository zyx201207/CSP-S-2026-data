#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> g[2000005];
int dis[20005];
int a[2000005];




int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,int t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
			q.push(a[i]);
		}
		for(int i = 1;i<=n;i++)
		{
			for(int j = i;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					g[u].push_back(v);
					g[v].push_back(u);
				}
			}
		}
		
		
		
	}
	return 0;
}
