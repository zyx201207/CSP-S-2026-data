#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n;
	int m;
	vector<char> vec(5);
	vector<char> vec2(5);
	cin >> n;

	for (int i = 1; i <= 3; ++i) {

		cin >> vec[i];
	}

	cin >> m;

	for (int i = 1; i <= 2; ++i) {

		cin >> vec2[i];
	}

	for (int i = 0; i < 2; ++i) {

		int flag = 0;

		for (int j = 0; j < 2; ++j) {

			if (n == m) {
				flag = 1;
			} else if (n == m && vec[1] == vec2[1] && vec[2] == vec2[2]) {
				flag = 1;
			} else if (n == m && vec[1] == vec2[1] && vec[2] == vec2[2] && vec[3] <= 'c' && vec2[3] <= 'c') {
				flag = 1;
			}
		}

		if (flag == 1) {
			cout << "1";
		} else {
			cout << "0";
		}
	}

	return 0;
}
