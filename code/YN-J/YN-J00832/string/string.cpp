#include <bits/stdc++.h>
using namespace std;
int n, len, num, tmp;
string str, tmp_s;

int hw(string str) {
	for (int i = 0; i < (len + 1) / 2; i++) {
		if (str[i] != str[len - i - 1])
			return i;
	}
	return -1;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		cin >> tmp >> tmp_s;
		while (tmp--) {
			str += tmp_s;
		}
	}
	len = str.size();
	while (true) {
		int tmp = hw(str);
		if (tmp == -1)
			break;
		str[tmp] = str[len - tmp - 1];
		num++;
	}
	cout << num;
	return 0;
}