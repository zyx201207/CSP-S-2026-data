#include <bits/stdc++.h>//*0.o Please fly!
using namespace std;
#define int long long
const int N = 3e5 + 5, M = 5e5 + 5;
int n, m, a[M], ans[M], f[M], l[M];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n;) {
			if (f[a[j]] > j) {
				j = f[a[j]];
			} else {
				ans[a[j]]++;
				j++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i];
		if (i != m)
			cout << " ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

I would be lost

Drifting alone

Floating up high

Time after time

And there you'll be

Shining brightly

Heal every wound

And make me hole

Was it all a dream

Will I ever know

Would you be here

In my enbrace?

Will I still be here next year?
I don't know
We used to crave in this
But now, everyone hate this
Why?
Yeah, no hope, no light
Still fighting against ourselves
Thank you, I'm really enjoyable
I bet we can meet each other again
I love programming
This is my honor

Luogu id: Vaati
*/