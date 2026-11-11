#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a[maxn], ans, d, di[maxn];
bool A = 1, B = 1, C = 1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] != i)A = 0;
		if (i == 2)d = a[2] - a[1]; 
		if (i >= 2)
			if (a[i] - a[i - 1] != d)B = 0;
		if (abs(a[i]) > 100)C = 0;
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			int cur = m, sum = 0;
			for (int j = i; j >= 1; j--) {
				cur -= a[i] - a[j];
				if (cur >= 0)sum++;
				else break;
			}
			ans = max(ans, sum);
		}
		cout << ans << '\n';
		return 0;
	}
	if (A) {
		for (int i = 1; i <= n; i++)
			if (n * (n - 1) / 2 <= m)ans++;
			else break;
		cout << ans << '\n';
		return 0;
	}
	if (B) {
		for (int i = 1; i <= n; i++)
			if (n * (n - 1) / 2 * d <= m)ans++;
			else break;
		cout << ans << '\n';
		return 0;
	}
	if (C) {
		for (int i = -100; i <= 100; i++) {
			int tot = 0, cur = m;
			for (int j = 1; j <= n; j++) {
				if (i < a[j])break;
				di[++tot] = i - a[j];
			}
			sort(di + 1, di + tot + 1);
			int sum = 0;
			for (int j = 1; j <= tot; j++) {
				cur -= di[j];
				if (cur < 0)break;
				else sum++;
			}
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
It's been a long day
Without you my friend
I'll tell you all about it when I see you again
We've come a long way 
From where we began
Oh I'll tell you all about it when I see you again
When I see you again

rap

It's been a long day
Without you my friend
I'll tell you all about it when I see you again
We've come a long way 
From where we began
Oh I'll tell you all about it when I see you again
When I see you again

Ao-o-o-o Ao-o-o-o-o-o
oh-oooo-ho-ho-ho When I see you again

rap

So let the light guide yeah way
Hold the the memory as you go
????
Always lead you home 
Home

It's been a long day
Without you my friend
I'll tell you all about it when I see you again
We've come a long way 
From where we began
Oh I'll tell you all about it when I see you again
When I see you again

Ao-o-o-o Ao-o-o-o-o-o
oh-oooo-ho-ho-ho When I see you again

Ao-o-o-o Ao-o-o-o-o-o
oh-oooo-ho-ho-ho When I see you again

            -- ¡¶Road and laugh 7¡· ¡¶See You Again¡·
To you, who sit in f 
*/ 
