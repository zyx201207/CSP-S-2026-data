#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 5;
char arr_1[N];
char arr_2[N];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, c2, s1, s2;
	int cnt1 = 0, cnt2 = 0;
	string jg = "0000";
	cin >> c1;

	for (int i = 1; i <= 3; i++) {
		cin >> arr_1[i];
	}
	cin >> c2;
	for (int i = 1; i <= 3; i++) {
		cin >> arr_2[i];
	}

	if (arr_1[3] >= 'A' and arr_1[3] <= 'C') {
		cnt1 = 1;
	}
	if (arr_2[3] >= 'A' and arr_2[3] <= 'C') {
		cnt2 = 1;
	}
	if (arr_1[3] == 'D' or arr_1[3] == 'F') {
		cnt1 = 2;
	}
	if (arr_2[3] == 'D' or arr_2[3] == 'F') {
		cnt2 = 2;
	}

	if (c1 == c2) {
		jg = "1000";
		if (arr_1[1] == arr_2[1] and arr_1[2] == arr_2[2] ) {
			jg = "1100";
			if (cnt1 == cnt2) {
				jg = "1110";
				if (arr_1[3] - 1 == arr_2[3] or arr_1[3] + 1 == arr_2[3])
					jg = "1111";
			}
		}

	}
	cout << jg;

	return 0;
}