# include<bits/stdc++.h>
using namespace std;
string rx, rz, xx, xz;

char a[10] {'A', 'B', 'C', 'D', 'F'};
map<int, char>mp;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rx >> rz >> xx >> xz;
	for (int i = 0; i < 5; i++) {
		mp[a[i]] = i + 1;
		if (a[i] == 'D' || a[i] == 'F') {
			mp[a[i]] = i + 2;
		}
	}
	if (rx == xx) {
		printf("1");
	} else {
		printf("0");
	}
	bool flag = 0;
	for (int i = 0; i < 2; i++) {
		if (rz[i] != xz[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("1");
	} else {
		printf("0");
	}
	char zc1 = rz[2];
	char zc2 = xz[2];
	if ((mp[zc1] <= 3 && mp[zc2] <= 3) || (mp[zc1] > 3 && mp[zc2] > 3)) {
		printf("1");
	} else {
		printf("0");
	}
	if (mp[zc1] + 1 == mp[zc2] || mp[zc1] - 1 == mp[zc2]) {
		printf("1");
	} else {
		printf("0");
	}
	return 0;
}