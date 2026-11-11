#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<char> vec(2000);
	int num = 0;
	for (int i = 0; i < n; i++) {
		int shu;
		cin >> shu;
		char s;
		cin >> s;
		for (int i = 0; i < shu; i++) {
			vec[i] = s;
		}
		num += shu;
	}
	vector<int> vec1(1000);
	vector<int> vec2(1000);
	for (int i = 0; i < num / 2 + 1; i++) {
		vec1[i] = vec[i];
		vec2[vec2.size() - i] = vec[i];

	}
	int sum = 0;
	for (int i = 0; i < num / 2 + 1; i++) {
		if (vec1[i] != vec2[vec2.size() - 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}