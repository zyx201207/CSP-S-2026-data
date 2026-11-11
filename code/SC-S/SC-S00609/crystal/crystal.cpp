#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5 * 1e5 + 10;
int n,m,a[N],s[N],maxx;
int dis(int l,int r)
{
	return s[l] - s[r + 1] - (r - l + 1) * (a[n] - a[r]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i=n;i>=1;i--)
	{
		s[i] = s[i + 1] + (a[n] - a[i]);
	}
	int l = 1,r = 1;
	while(r <= n)
	{
		int req = dis(l,r);
		if(req > m && l < r)
		{
			while(req > m && l < r)
			{
				l ++;
				req = dis(l,r);
			}
		}
		if(req <= m) maxx = max(r - l + 1,maxx);
		r ++; 
	}
	cout<<maxx; 
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/