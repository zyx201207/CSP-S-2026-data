#include <bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],sa[500010],ssa[500010];
int n;
long long m;
bool check(int x,int y)
{
	return ssa[y] - ssa[x] - 1ll * (y - x) * sa[y + 1] <= m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 2; i <= n; i++)
	{
		b[i] = a[i] - a[i - 1];
	}
	for(int i = n; i >= 2; i--)
	{
		sa[i] = sa[i + 1] + b[i];
	}
	for(int i = 1; i <= n; i++)
	{
		ssa[i] = ssa[i - 1] + sa[i];
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++)
	{
		int l = i,r = n;
		while(l + 1 < r)
		{
			int mid = (l + r) / 2;
			if(check(i,mid))
			{
				l = mid;	
			}	
			else
			{
				r = mid;
			}
		} 
		maxn = max(maxn,l - i + 1);
	}
	cout << maxn << endl;
	return 0;
 } 