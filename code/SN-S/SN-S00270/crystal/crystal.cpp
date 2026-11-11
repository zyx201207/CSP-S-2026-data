#include <bits/stdc++.h>
#define int long long
using namespace std;
int l, t, k, n, m;
const int N = 6e5;
map <int, int> a, les;
pair <int, int> dif[N];
int ans, ans1, lesnum[N];

signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> t, a[t]++;
	for (auto x : a)
		for (auto it : a)
			les[x.first] += abs((it.first - x.first) * it.second);

	for (auto x : les) if (les[lesnum[0]] > les[x.first]) lesnum[0] = x.first;
	for (auto x : les)
		if (les[lesnum[0]] >= les[x.first] - les[x.first] / 8) lesnum[++k] = x.first;

//	for (int i = 0; i < k; i++) cout << i << " " << lesnum[i] << "nn " << les[lesnum[i]] << "--------";//sehfj
//	cout << endl << n << " " << m << endl;//tyhr
//	for (auto x : a) cout << x.first << ":" << x.second << " ";//tjrs
//	cout << endl;//tuyrs
//	for (auto x : les) cout << x.first << ":" << x.second << " ";//sedtg

	for (int j = 0; j < k; j++) {
//		map <int, int> les2;//fthth
//		cout << endl << j << "--------" << lesnum[j] << " " << les[lesnum[j]] << endl;//fthf
//		for (auto x : les) les2[x.first] = lesnum[j] - x.first;//tftfh
//		for (auto x : les2) cout << x.second << " ";//fthft
//		cout << endl;//yrth

		l = 0, t = m;
		for (auto x : a) {
			if (lesnum[j] > x.first) {
				dif[l++] = make_pair((lesnum[j] - x.first) * x.second, x.first);
//				cout << x.first << "__" << lesnum[j] << " ";//ghmgm
			}
		}
		sort (dif, dif + l);
//		for (int t1 = 0; t1 < l; t1++) cout << dif[t1].first << "--" << dif[t1].second << " ";//ghmggh

		ans1 = a[lesnum[j]];
//		cout << endl << ans1 << endl;//ghmgg
		if (les[lesnum[j]] <= m) {
			cout << n << endl;
			return 0;
		}
		l = 0;
		while (t) {
			while (t && dif[l].first) dif[l] = make_pair(dif[l].first - 1, dif[l].second), t--;
//			cout << i << ": " << dif[i].first << " " << dif[i].second << "\n";//ghmhg
			if (dif[l].first == 0) ans1++, l++;
		}
//		cout << "fd\t" << ans1 << "\tfg\n";//hhhh
		ans = max (ans, ans1);
	}
	
	cout << ans;
	return 0;
}
