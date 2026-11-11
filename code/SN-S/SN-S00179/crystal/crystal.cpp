#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll n, m, aver, clc=1, cmc=1, ans;
ll a[500005];
ll cl[500005];
bool cmp(ll a, ll b)
{
	return a>b;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		aver+=a[i];
	}
	aver/=n;
	cout << aver << "\n";
	for (int i=1;i<=n;i++)
	{
		if (a[i]-aver<0)
		{
			cl[clc]=aver-a[i];
			clc++;
		} 
		else if (a[i]-aver==0)
		{
			ans++;
		}
	}
	sort(cl+1, cl+clc);
	for (int i=1;i<=n;i++)
	{
		cout << "cl:" << cl[i] << "\n";
	}
	for (int i=1;i<=clc;i++)
	{
		if (m==0)
		{
			break;
		}
		if (cl[i]<=m)
		{
			m-=cl[i];
			ans++;
			cout << m << "\n";
		}
		else
		{
			break;
		}
	}
	cout << ans;
}
/*
5 8
-3 -1 2 2 7
*/
