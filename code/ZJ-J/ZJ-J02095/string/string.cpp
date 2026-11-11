#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 10;
struct str
{
	ll len;
	char ch;
}a[MAXN];
int n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].len >> a[i].ch;
	ll ans = 0;
	ll llen = 0, rlen = 0;
	for(int i = 1, j = n; i <= n; i++)
	{
		while(j >= 1 && rlen + a[j].len <= llen + a[i].len)
		{
			if(a[i].ch != a[j].ch)
			{
				if(rlen < llen)ans += a[j].len - (llen - rlen);
				else ans += a[j].len;
			}
			rlen += a[j].len;
			j--;
		}
		llen += a[i].len;
		if(llen == rlen)continue;
		if(a[i].ch != a[j].ch)ans += min(llen - rlen, a[i].len);
	}
	cout << ans / 2 << '\n';
}