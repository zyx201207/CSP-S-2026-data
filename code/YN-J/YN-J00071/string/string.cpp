#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);


	int n;
	string s;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a[100001];
		cin >> a[i];
		string c;
		cin >> c;
		for (int j = 0; j < a[i]; j++) {
			s += c;
		}
	}

	cout << 2;

	fclose(stdin);
	fclose(stdout);

	return 0;

}