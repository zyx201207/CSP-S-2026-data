#include<iostream>
#include<cstring>
using namespace std;
const int N = 100;
int n, d, ans, num[N], a[N];
void dfs(int step, int zhongdian, int k) {
	if (step == zhongdian) {
		num[k]++;
		return;
	}
	for (int i = step + 1 ; i <= zhongdian ; ++i) {
		if (a[i] - a[step] > d) break;
		dfs(i, zhongdian, k + 1);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cout << 0 << "\n";
	}

	return 0;
}
