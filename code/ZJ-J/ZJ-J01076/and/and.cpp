#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010], ans;
int mxl;
bool f[200010][100];
int mlg(int x)
{
	long long t = a[x];
	int cnt = 0;
	while(t > 0)
	{
		if(t & 1)	f[x][++cnt] = 1;
		else		f[x][++cnt] = 0;
		t /= 2;
	}
	return cnt;
}
long long mpw(int x, int y)
{
	long long r = x, p = 1;
	while(y > 0)
	{
		if(y & 1)	p *= r;
		r *= r;	
		y /= 2;
	}
	return p;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		mxl = max(mxl, mlg(i));
	for(int i = 1; i <= n; i++)
		f[i][0] = 1;
	for(int i = mxl; i >= 1; i--)
	{
		int num = 0;
		for(int j = 1; j <= n; j++)	num += (f[j][i] * f[j][0]);
		if(num < m)	continue;
		for(int j = 1; j <= n; j++)	f[j][0] *= f[j][i];
		ans += mpw(2, i - 1);
	}
	cout << ans << endl;
	return 0;
}
