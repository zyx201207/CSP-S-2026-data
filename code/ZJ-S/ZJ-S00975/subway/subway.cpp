#include<bits/stdc++.h>
using namespace std;
//typedef long long LL;
long long MAXN = 10;
long long c , n , m , d , q , w[1010] , k , a[1010][2] , plan[1010][2] , tu[1010][1010] , landian[1010];
long long ans[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	//memset(tu , 1000000010 , sizeof(tu));
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			tu[i][j] = 1000000010;
		}
	}/*
	cout << MAXN << '\n';
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout << tu[i][j] << ' ';
		}
		cout << '\n';
	}*/
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> a[j][0] >> a[j][1];
			for(int l = 1; l < j; l++)
			{
				tu[a[l][0]][j] = min(tu[a[l][0]][j] , a[a[l][0]][1] + a[j][1]);
				//cout << a[a[l][0]][1] << ' ' <<  a[j][1] << ' ';
				tu[j][a[l][0]] = tu[a[l][0]][j];
			}
		}
	}
	//cout << '!';
	/*for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout << tu[i][j] << ' ';
		}
		cout << '\n';
	}*/
	for(int i = 1; i <= q; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			ans[j] = 1000000010;
		}
		memset(landian , 0 , sizeof(landian));
		cin >> plan[i][0] >> plan[i][1];
		ans[plan[i][0]] = 0;
		long long cnt = 1;
		//cout << '!';
		while(cnt <= m)
		{
			bool flag = true;
			long long cur;
			for(int j = 1; j <= m; j++)
			{
				if(landian[j] == 0 && flag || landian[j] == 0 && ans[j] < ans[cur])
				{
					cur = j;
					flag = false;
				}
			}
			/*
			for(int j = 1; j <= m; j++)
			{
				if(flag && landian[j] == 1)
				{
					continue;
				}
				else if(flag)
				{
					flag = false;
					cur = j;
				}
				if(landian[cur] == 0 && ans[j] < ans[cur])
				{
					cur = j;
				}
			}*/
			//cout << cur << '\n';
			landian[cur] = 1;
			cnt++;
			for(int j = 1; j <= m; j++)
			{
				if(cur != j && tu[cur][j] != MAXN)
				{
					ans[j] = min(ans[j] , ans[cur] + tu[cur][j]);
				}
			}
		}
		//cout << '!';
		cout << ans[plan[i][1]] + w[plan[i][0]] + w[plan[i][1]] << '\n';
	}
	return 0;
}
