#include <bits/stdc++.h>
#define ll long long 
using namespace std;
struct node
{
	ll a;
	char c;
}ch[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, cnt = 0, x = 0, y = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> ch[i].a >> ch[i].c;
		cnt += ch[i].a;
	}
	ll t = cnt / 2, st = n, st1 = 1, st2 = n, ans = 0, ycl = 0;
	char sz1, sz2;
//	for (int i = 1; i <= n; i ++)
//		cout << ch[i].a << " " << ch[i].c << endl;
//	if (cnt % 2 == 0) st = t + 1;
//	else st = t + 2;
	//cout << x << y << endl;
	while(ycl < t)
	{
		if (x == 0) x = ch[st1++].a, sz1 = ch[st1 - 1].c;
		if (y == 0) y = ch[st2--].a, sz2 = ch[st2 + 1].c;
		if (t - ycl >= x)
		{
			int cc = min(x, y);
			ycl += cc;
			if (sz1 == sz2) x -= cc, y -= cc;
			else ans += cc, x -= cc, y -= cc;
		}
		else
		{
			x = t - ycl;
			int cc = min(x, y);
			ycl += cc;
			if (sz1 == sz2) x -= cc, y -= cc;
			else ans += cc, x -= cc, y -= cc;
		}
		//cout << x << " " << sz1 << " " << y << " " << sz2 << " " << ans << endl;
	}
	cout << ans << endl;
	return 0;
} 
