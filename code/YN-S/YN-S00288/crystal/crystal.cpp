#include <bits/stdc++.h>
using namespace std;
int a[1000];

int main() {
	freopen("ctystal.in", "r", stdin);
	freopen("ctystal.out", "w", stdout);
	

	long long n;
	int m;
	int ans = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	
	for (int i = 1; i <= n; i++) {

		int min;

		if (min < a[i]) {
			min += 1;
			ans++;
		}

		


	while (true)	{
		break;
	}

	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
