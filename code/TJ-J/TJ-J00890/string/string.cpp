#include <bits/stdc++.h>
using namespace std;
int n;
long long len,a[200005],p[200005],ans = 0;
char c[200005];
struct STR{
	int d;
	char b;
	long long l,r;
};
vector<STR> s;
STR x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int y;
		char z;
		cin >> y >> z;
		if (z == c[i-1]) 
		{
			a[i-1] += y;
			n--;
			i--;
			len += y;
			continue;
		}
		a[i] = y,c[i] = z;
		p[i] = p[i-1] + a[i];
		len += a[i];
	}
	if (len % 2 == 0) len /= 2;
	else len = len / 2 + 1;
	int m = 0;
	bool st = 0;
	for (int i = 1;i <= n;i++)
	{
		if ((p[i] <= len && st == 0) || ((p[i]-a[i]+1) <= len && st == 0))
		{
			x.d = a[i];
			x.b = c[i];
			x.r = 2*len - p[i];
			x.l = 2*len - (p[i]-a[i]+1);
			s.push_back(x);
			m++;
		}
		else
		{
			st = 1;
			if (s[m].l >= p[i]) 
			{
				a[i+1] -= (s[m].l - p[i]);
				if (c[i+1] != s[m].b)
					ans += (s[m].l - p[i]);
			}
			else
			{
				s[m-1].l += (p[i] - s[m].l),s[m-1].d -= (p[i] - s[m].l);
				if (s[m-1].b != c[i])
					ans += (p[i] - s[m].l);
			}
			if (c[i] != s[m].b)
			{
				ans += a[i];
			}
			m--;
		} 
	}
	cout << ans << endl;
	return 0;	
} 
