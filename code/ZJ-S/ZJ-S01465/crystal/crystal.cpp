#include <bits/stdc++.h>
using namespace std;

long long a[500005],p[500005],f[500005];
int n;
long long m;

bool ch(int x)
{
	if(f[x] <= m)
		return true;
	for(int i = x + 1;i <= n;i++)
		if(f[i] - f[i-x+1] - (a[i] - a[i-x+1]) * (i - x) <= m)
			return true;
	return false;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
		f[i] = (a[i] - a[i-1]) * (i - 1) + f[i-1];
	int l = 1,r = n;
	while(l < r)
	{
		int mid = (l + r + 1) >> 1;
		if(ch(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l;
	return 0;
}
