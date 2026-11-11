#include <iostream>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	vector<vector<int>> v;
	for (int i = 0; i < 18; i++) {
		for (int j = 0; i < 5; j++) {
			int t;
			cin >> t;
			v.push_back(t);
		}
	}
	int s, h
	int c = c1;
	int s = c2;
	for (int i = 0; i < 18; i++) {
		for (int j = 0; i < 5; j++) {
			if (c == s) {
				cout << 1;
				s = true;
			} else {
				cout << 0;
				s = false;
			}

		}
	}
//	fclose(travel);
//	fclose(travel);
	return 0;
}