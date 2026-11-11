#include <bits/stdc++.h>
using namespace std;
int m, n, num[200001], ans, choose_number;
bool choose[200001];

void dfs(int this_ans) {
	if (choose_number == m) {
		ans = max(ans, this_ans);
		return;
	}
	if (choose_number == 0) {
		for (int i = 1; i <= n; i++) {
			choose[i] = 1;
			choose_number++;
			dfs(num[i]);
			choose[i] = 0;
			choose_number--;
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (choose[i] == 1) {
				continue;
			}
			choose[i] = 1;
			choose_number++;
			dfs(num[i]&this_ans);
			choose[i] = 0;
			choose_number--;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	dfs(0);
	printf("%d\n", ans);
}