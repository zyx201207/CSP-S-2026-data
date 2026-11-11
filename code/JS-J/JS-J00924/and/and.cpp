#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long a[200005];

void dfs(long long x,long long m1,long long s)
{
	if(m1 == 0)
	{
		ans = max(ans,s);
		//cout << ans << " " << m1 << endl;
		return;
	}
	if(x == n + 1)
	{
		if(m1 == 0)
		{
			ans = max(ans,s);
			//cout << ans << " " << m1 << endl;
		}
		return;
	}
	dfs(x + 1,m1,s);
	s = s & a[x];
	dfs(x + 1,m1 - 1,s);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == n)
	{
		ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n - m + 1;i++)
	{
		dfs(i + 1,m - 1,a[i]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
