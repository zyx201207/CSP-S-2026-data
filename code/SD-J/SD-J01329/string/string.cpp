#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct Node{
	ll m;
	char c;
} a[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int tot = 0;
	for(int i = 1; i <= n; i ++)
	{
		ll num;
		char ch;
		cin >> num >> ch;
		if(ch == a[tot].c)
			a[tot].m += num;
		else
			a[++tot] = {num, ch};
	}
	if(tot == 1)
	{
		cout << 0;return 0;
	}
	ll ans = 0;
	int l = 1, r = tot;
	while(l <= r)
	{
		if(a[l].c == a[r].c)
		{
			if(a[l].m > a[r].m) {
				a[l].m -= a[r].m;r --;
			} else if(a[l].m == a[r].m) {
				l ++;r --;
			} else {
				a[r].m -= a[l].m;l ++;
			}
		}
		else
		{
			if(a[l].m > a[r].m) {
				ans += a[r].m;
				a[l].m -= a[r].m;
				r --;
			} else if(a[l].m == a[r].m) {
				ans += a[l].m;
				l ++;r --;
			} else {
				ans += a[l].m;
				a[r].m -= a[l].m;
				l ++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
