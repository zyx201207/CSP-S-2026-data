#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005],na[100005],maxn = -1;
void dfs(int step)
{
	if(step > m)
	{
		int y = na[1];
		for(int i = 2;i<=m;i++)
		{
			y = int(y & na[i]);
		}
		maxn = max(maxn,y);
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(na[step-1] < a[i])
		{
			na[step] = a[i];
			dfs(step + 1);
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout << maxn;
	
	return 0;
}
