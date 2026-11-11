#include <bits/stdc++.h>
using namespace std;

struct node {
	long long a;
	string b;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	node m[20005];
	long long n, sum = 0, cnt = 0, mid;
	string jio[555];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i].a >> m[i].b;
		sum += m[i].a;
	}
	//cout << sum << endl;
	if (sum % 2 != 0) {
		mid = sum / 2 + 1;
	} else {
		mid = sum / 2;
	}
	//cout << mid << endl;
	long long lin = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m[i].a; j++) {
			jio[lin] = m[i].b;
			lin++;
		}
	}
	long long r = mid, l = mid;
	if (sum % 2 == 0) {
		r++;
	}
	//for (int i = 1; i <= lin; i++) {
	//	cout << jio[i] << " ";

	//}
	//cout << jio[r + 1] << " " << jio[l - 1];
	for (int i = 1; i <= mid + 1; i++) {
		//cout << jio[r] << jio[l];
		if (jio[l] != jio[r]) {
			cnt++;
			//cout << r << " " << l << " " << cnt << endl;
		}
		r++;
		l--;
		if (l == 0 && r == sum) {
			break;
		}
	}
	cout << cnt;
	return 0;
}