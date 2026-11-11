#include<bits/stdc++.h>
using namespace std;
struct str
{
	int a;
	char c;
} s[200002];
int n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i].a >> s[i].c;
	int l = 1, r = n;
	long long ans = 0;
	while(l < r)
	{
		int minn = min(s[l].a, s[r].a);
		if(s[l].c != s[r].c) ans += minn;
		s[l].a -= minn;
		s[r].a -= minn;
		if(s[l].a == 0) l++;
		if(s[r].a == 0) r--;
	}
	cout << ans;
	return 0;
}