#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
struct C
{
	int cnt;
	char c;
}s[maxn];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i].cnt;
		cin >> s[i].c;
	}
	int l = 1, r = n;
	ll ans = 0;
	while(l < r)
	{
		int Min = min(s[l].cnt, s[r].cnt);
		if(s[l].c != s[r].c)ans += 1ll * Min;
		s[l].cnt -= Min;
		s[r].cnt -= Min;
		if(!s[l].cnt)l++;
		if(!s[r].cnt)r--;
	}
	printf("%lld\n", ans);
	return 0;
}
