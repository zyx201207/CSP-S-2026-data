#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long k[500005];
vector<int> a[505];
vector<long long> t[505];
vector<int> lin[500005];
vector<int> tie[500005];
int tmpa;
long long tmpt;
long long di[505][505];
int x,y;
long long ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%ld%ld%ld%ld%ld",&c,&n,&m,&d,&q);
	for (int i = 1;i <= m;i ++)
	{
		scanf("%ld",&w[i]);
	}
	for (int i = 1;i <= n;i ++)
	{
		for (int j = 1;j <= n;j ++)
		{
			di[i][j] = 4e18;
			if (i == j)di[i][j] = 0;
		}
	}
	for (int i = 1;i <= n;i ++)
	{
		scanf("%ld",&k[i]);
		for (int j = 1;j <= k[i];j ++)
		{
			scanf("%d%ld",&tmpa,&tmpt);
			a[i].push_back(tmpa);
			t[i].push_back(tmpt);
			lin[tmpa].push_back(i);
			//cout << tmpa << "<>" << i << endl;
			tie[tmpa].push_back(tmpt);
			for (int l = 0;l < lin[tmpa].size() - 1;l ++)
			{
				di[lin[tmpa][l]][i] = min(di[lin[tmpa][l]][i],t[i][t[i].size() - 1] + tie[tmpa][l]);
				di[i][lin[tmpa][l]] = di[lin[tmpa][l]][i];
			}
		}
	}
	for (int k = 1;k <= n;k ++)
	{
		for (int i = 1;i <= n;i ++)
		{
			for (int j = 1;j <= n;j ++)
			{
				if (di[i][k] + di[j][k] < di[i][j])
				{
					di[i][j] = di[i][k] + di[j][k];
				}
			}
		}
	}
	/*
	for (int i = 1;i <= m;i ++)
	{
		for (int j = 0;j < lin[i].size();j ++)
		{
			cout << tie[i][j] << " ";
		}
		cout << endl;
	}*/
	while(q --)
	{
		ans = 4e18;
		cin >> x >> y;
		for (int i = 0;i < lin[x].size();i ++)
		{
			for (int j = 0;j < lin[y].size();j ++)
			{
				ans = min(ans,di[lin[x][i]][lin[y][j]] + tie[x][i] + tie[y][j] + w[x] + w[y]);
			}
		}
		//printf("%ld\n",ans);
		cout << ans << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
//33961573wwh
//15:02   O(m^2)TLEEE做法
//15:14   O(n^3)不会TLE做法 
//15:35   O(kRP^-1)RP做法 
//15:39   大脑:O(inf) 