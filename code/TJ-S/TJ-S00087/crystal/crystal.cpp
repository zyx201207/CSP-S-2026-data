#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for (int i=1;i<=m;i++)
	{
		int j=1;
		while (j+1<=n)
		{
			if (a[j]<=a[j+1])
			{
				break;
			}
			j++;
		}
		a[j]++;
	}
	int maxx=10000000000000,maxn=-1;
	int tempx=10000000000000,tempn=-1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=tempx)
		{
			if (tempn>maxn)
			{
				maxn=tempn;
				maxx=tempx;
			}
			tempx=a[i];
			tempn=1;
		}
		else
		{
			tempn++;
		}
	}
	if (tempn>maxn)
	{
		maxn=tempn;
	}
	cout<<maxn;
	return 0;
}
