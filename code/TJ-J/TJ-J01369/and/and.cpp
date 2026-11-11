#include <bits/stdc++.h>
using namespace std;
long long n,m,sum = 0,a[1000001],o = 1,k = 1;
bool dfs(long long ans,long long c,long long g)
{
	if(g == m)
	{
		sum = max(sum,ans);
		return 0;
	}
	if(g > n)
	{
		return 0;
	}
	if(g + n - c + 1 < m)
	{
		return 0;
	}
	dfs(ans & a[c],c + 1,g + 1);
	dfs(ans,c + 1,g);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= 21;i++)
	{
		o *= 2;
		k += o;
	}
	dfs(k,1,0);
	cout << sum;
	return 0;
}
