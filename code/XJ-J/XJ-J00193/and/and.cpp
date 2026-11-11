#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],sum;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	if (n==1)
	{
		cout << a[1];
		return 0;
	}
	if (n==2)
	{
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout << maxn;
		return 0;
	}
	for (int i = 2; i <= m; i++)
	{
		sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
} 
