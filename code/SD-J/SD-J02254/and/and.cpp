#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx=0;
bool f[200005];
void dfs(int x)
{
	if (x>m)
	{
		int d;
		bool g=1;
		for (int i=1; i<=n; i++)
		{
			if (f[i] && g)
			{
				d=a[i];
				g=0;
			}
			else if (f[i])
			{
				d&=a[i];
			}
		}
		mx=max(mx,d);
		return;
	}
	for (int i=1; i<=n; i++)
	{
		if (!f[i])
		{
			f[i]=1;
			dfs(x+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	if (m==1)
	{
		int mxn=0;
		for (int i=1; i<=n; i++)
		{
			mxn=max(mxn,a[i]);
		}
		cout << mxn;
	}
	else if (m==n)
	{
		int mxn=a[1];
		for (int i=2; i<=n; i++)
		{
			mxn&=a[i];
		}
		cout << mxn;
	}
	else if (m==2)
	{
		int mxn=0;
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				mxn=max(mxn,a[i]&a[j]);
			}
		}
		cout << mxn;
	}
	else
	{
	    dfs(1);
		cout << mx;
	}
	return 0;
}
