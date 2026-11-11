#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string t;
	for (int i = 0; i < n; i++) {
		int y;
		char a;
		cin >> y >> a;
		for (int j = 0; j < y; j++){
			t = t + a;
		}
	}
	int ans = 0;
	for (long long i = 0; i * 2 <= (long long)t.size(); i++){
		if (t[i] != t[t.size() - i - 1]) {
			ans++;
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
