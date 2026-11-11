#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c,maxn=1,b[500005],f;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		b[i] = a[i] - a[i-1];
		if(i>=3&&b[i]!=b[i-1]) f = 1;
	}
	if(f)
	{
		sort(a+1,a+n+1);
		for(int i = 1;i<=n;i++)
		{
			c = 0;
			for(int j = i-1;j>=1;j--)
			{
				c += a[i]-a[j];
				if(c>m) break;
				if(maxn<i-j+1) maxn = i-j+1;
			}
		}
	}
	else
	{
		while(c<=m)
		{
			c+=b[2];
			if(c<=m) maxn++;
		}
	}
	cout << maxn;
	return 0;
}
