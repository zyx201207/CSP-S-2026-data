#include <bits/stdc++.h>
#define  int long long
using namespace std;

const int N = 2e5 + 10;
int n, m;
struct Node
{
	char c;
	int len;
} a[N];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		char s;
		cin >> x >> s;
		a[i].c = s;
		a[i].len = x + a[i - 1].len;
		m += x;
	}
//	for(int i = 1; i <= n; i ++)
//	{
//		cout << a[i].c << " " << a[i].len << endl;
//	}
	int l = 1, r = n, ans = 0;
	int pos = 1;
	while(pos <= m / 2 && l <= r)
	{
		if(l == r) break;
		int cnt = min(a[l].len - pos + 1, 
		m + 1 - pos - a[r - 1].len);
		if(a[l].c == a[r].c) pos += cnt;
		else pos += cnt, ans += cnt;
		if(pos > a[l].len) l ++;
		if(m + 1 - pos <= a[r - 1].len) r --;
	}
	cout << ans << endl;
	return 0;
}
//1000000000
