#include <bits/stdc++.h>
using namespace std;
long long n, m, cha[500005], jia[500005], ch[500005], zh[500005];
long long a[500005];

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	// ‰»Î
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) {
			if ((m >= (i + 1) * i / 2) && (m < (i + 1) * (i + 2) / 2)) {
				cout << i + 1 ;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if ((a[i + 1] - a[i]) == (a[i + 2] - a[i + 1])) {
			int c = a[2] - a[1];
			if (m < c)
				cout << 0;
			else if (m == c)
				cout << 1;
			else {
				int d = m / c;
				cout << d / 2;
			}
			return 0;
		}
	}
	sort(a + 1, a + n + 1);
	int minn = 100110, biao = 0;
	for (int i = 2; i <= n; i++) {
		cha[i] = a[i] - a[i - 1];
		//cout << cha[i] << " ";
	}

	for (int i = 2; i < n; i++) {
		ch[i] = cha[i] + cha[i + 1];
		//cout << ch[i] << "°°";
		if (ch[i] <= minn) {
			minn = ch[i];
			biao = i;
		}
	}
	//cout << minn << " " << biao;
	jia[biao + 1] = cha[biao + 1];

	zh[biao + 1] = jia[biao + 1];
	long long cnt = 2;
	for (int i = biao; i >= 2; i--) {
		jia[i] = jia[i] + cha[i] + jia[i + 1];

		//cout << endl;
		zh[i] = zh[i + 1] + jia[i];
		//cout << zh[i] << " ";
		cnt++;
		if ((m <= zh[i]) && (m > zh[i + 1])) {
			//cout << zh[i] << " " << zh[i + 1];
			//cout << endl;
			cout << cnt;
		}

	}
	//for (int i = 2; i <= biao; i++) {
	//if ((m <= zh[i]) && (m > zh[i + 1])) {
	//	cout << zh[i] << " " << zh[i + 1];
	//}
	//}
	//for (int i = 2; i <= biao + 1; i++) {
	//cout << zh[i] << " ";
//	}
	return 0;
}