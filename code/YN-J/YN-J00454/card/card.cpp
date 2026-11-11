#include <iostream>

using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int arr[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= m; i++) {
		int cnt = 0, cnt2 = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[j] == i) {
				for (int k = j + 1; k <= n; k++) {
					if (arr[k] == arr[j])
						cnt++;
					else
						break;
				}
			}
			if (cnt % 2 == 1) {
				cnt2 += 1;
			}
		}
		cout << cnt2 << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}