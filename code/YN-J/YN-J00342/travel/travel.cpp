#include <bits/stdc++.h>

using namespace std;

int n, m;
string str1, str2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> str1 >> m >> str2;

	if (n == m) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}

	if (str1[0] == str2[0] && str1[1] == str2[1]) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}

	if (str1[2] >= 'A' && str1[2] <= 'C' && str2[2] >= 'A' && str2[2] <= 'C' || str1[2] >= 'D' && str1[2] <= 'F'
	        && str2[2] >= 'D' && str2[2] <= 'F') {
		cout << 1;
	} else {
		cout << 0 << 0;
		return 0;
	}

	if (str1[2] == str2[2] + 1 || str1[2] == str2[2] - 1) {
		cout << 1;
	} else {
		cout << 0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}