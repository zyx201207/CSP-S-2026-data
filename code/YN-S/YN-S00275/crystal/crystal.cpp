#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll a[500005], pre[500005];
ll findpos(ll now_pos, ll *p, ll n, ll re) {
	ll now_pre = p[now_pos];

	if (now_pre == 0)
		now_pre = 1e18 + 1;
	ll step_pos = now_pos;
	ll step_pre = now_pre;

	for (ll i = step_pos; i <= n; i++) {

		if (p[i] > re)
			break;
		else if ((p[i] <= re)) {
			if (p[i] > step_pre)
				break;

			if (now_pre >= p[i] && p[i] != 0) {
				now_pos = i;
				now_pre = p[i];
			} else if (now_pre < p[i] && p[i] != 0)
				break;
		}

	}

	if (now_pre == 1e18 + 1 && pre[n] == 0) {
		now_pos = n;
		now_pre = 0;
	}

	if (now_pre == 1e18 + 1 && now_pos == step_pos)
		now_pos = findpos(1, p, n, re);
	return now_pos;
}


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m, remain_times, c_number = 0, ok_number = 0;
	cin >> n >> m;

	for (ll i = 1; i <= n; i++)

		cin >> a[i];
	sort(a + 1, a + n + 1);
	remain_times = m;

	for (ll i = 1; i <= n - 1; i++) {

		pre[i] = a[i + 1] - a[i];

		if (pre[i] == 0)
			c_number++;
	}

	if (a[n] - a[1] == 0)
		c_number++;

	ll spos = 1;

	while (remain_times > 0) {
		ll now_pos = spos;
		ok_number = n - 1;
		spos = findpos(spos, pre, n - 1, remain_times);

		if (pre[spos] > remain_times && spos == now_pos ) {
			while (true) {
				if (pre[spos] <= remain_times)
					break;
				spos = findpos(spos + 1, pre, n - 1, remain_times);

				if (remain_times == 0)
					break;
			}
		}

		if (remain_times == 0)
			break;

		if (spos == n - 1 && pre[spos] == 0 && pre[1] == 0) {
			remain_times = 0;
			c_number = n - 1;
			break;
		}

		if (remain_times == 0)
			break;

		if (pre[spos] <= remain_times && remain_times > 0) {
			remain_times -= pre[spos];
			a[spos] = a[spos + 1];
			pre[spos] = 0;
			c_number++;

			if (spos >= 2)
				pre[spos - 1] = a[spos] - a[spos - 1];

			if (spos == n - 1)
				spos = 1;
		}

		if (remain_times == 0)
			break;

		for (ll i = 1; i <= n - 1; i++) {

			if (pre[i] > remain_times || pre[i] == 0) {
				ok_number--;
			}
		}

		if (ok_number == 0)
			break;
	}

	cout << c_number << endl;

	return 0;
}
