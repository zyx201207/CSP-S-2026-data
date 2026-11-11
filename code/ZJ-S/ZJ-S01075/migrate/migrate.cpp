#include<bits/stdc++.h>
using namespace std;
int c, T;
int n;
long long d;
long long a[2000010];
int arrv[2000010];
int minstp;
int dfs(int x, int y, int stp)
{
	int num = 0, mn = 1e9 + 10;
	if(x == y)
	{
		minstp = stp;
		return 1;
	}
	for(int i = x + 1; i <= min(arrv[x], y); i++)
	{
		int e = dfs(i, y, stp + 1);
		if(mn > minstp)	num = e, mn = minstp;
		else if(mn == minstp)	num += e;
		else	continue;
	}
	minstp = mn;
	return num; 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)	cin >> a[i];
		int fl = 1;
		for(int i = 1; i <= n; i++)
			while(a[i] - a[fl] > d)	arrv[fl++] = i - 1;
		for(int i = fl; i <= n; i++)	arrv[i] = n;
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 2; j <= n; j++)
			{
				if(arrv[j - 1] == j - 1)	break;
				if(dfs(i, j, 0) == 2)	ans++;
			}
		cout << ans << "\n";
	}
	return 0;
}