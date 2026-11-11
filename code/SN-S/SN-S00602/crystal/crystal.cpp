//王昭云  西安市曲江第一学校  SN-S00602
#include <bits/stdc++.h>

using namespace std;

int n;
long long m,ans = -1,l,r,a[500005],b[500005];

long long check(long long x)
{
	long long tmpm = m,tot = 1;
	for(int i = 1;i < x;i++)
		b[i] = a[x] - a[i];
	sort(b + 1,b + x);
	for(int i = 1;tmpm > 0 && i < x;i++)
	{
		tmpm -= b[i];
		if(tmpm >= 0) tot++;
	}
	return tot;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
//	for(int i = 1;i <= n;i++)
//		ans = max(ans,check(i));
	l = 1,r = n;
	while(l <= r)
	{
		long long mid = (l + r) / 2;
		long long x = check(mid);
		if(x) ans = max(ans,x),l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}


