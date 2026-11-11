#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s;

bool checkHuiwen(string str) {
	string ns = "";
	for (int i = str.size() - 1; i >= 0; i--) {
		ns += str[i];
	}

	if (ns == str)
		return true;

	return false;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	vector<char> letters;
	for (int i = 0; i < n; i++) {
		long long x;
		char y;
		cin >> x;
		cin >> y;
		if (find(letters.begin(), letters.end(), y) == letters.end()) {
			letters.push_back(y);
		}
		for (int j = 0; j < x; j++) {
			s += y;
		}
	}
	vector<char> lst;
	vector<char> olst;

	for (int j = 0; j < letters.size(); j++) {
		for (int i = 0; i < s.size(); i++) {
			lst.push_back(letters[j]);
			olst.push_back(letters[j]);
		}
	}

	bool isHuiwen = checkHuiwen(s);
	if (isHuiwen) {
		cout << 0;
		return 0;
	}

	int ans = 999999;
	for (int i = 0; i < olst.size(); i++) {
		for (int j = i + 1; j < olst.size(); j++) {
			lst.clear();
			for (int a = 0; a < olst.size(); a++) {
				lst.push_back(olst[a]);
			}
			swap(lst[i], lst[j]);
			for (int x = 0; x < lst.size(); x++) {
				string ns = "";
				for (int y = x; y < x + s.size(); y++) {
					ns += lst[y];
				}
				if (!checkHuiwen(ns))
					continue;

				int nowChange = 0;
				for (int b = 0; b < s.size(); b++) {
					if (ns[b] != s[b]) {
						nowChange++;
					}
				}
				if (nowChange < ans) {
					ans = nowChange;
				}
			}
		}
	}

	cout << ans;

	return 0;
}