#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
int n, m;
ULL ans = 0;
bool v[200000];
ULL a[200000], maxx;
void dfs(ULL sum, int s)
{
	if(s==m)
	{
		ans = max(ans, sum);
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i] = 1;
			dfs(sum&a[i], s+1);
			v[i] = 0;
		}
	}
}
int main()
{
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
	cin >> a[i];	
	maxx = max(maxx, a[i]);
	}
	dfs(1000000000, 1);
	if(m==1)
	{
		cout << maxx;
		return 0;
	}
	cout << ans;
	return 0;
}
