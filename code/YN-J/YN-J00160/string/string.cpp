#include <bits/stdc++.h>
using namespace std;
char data_mine[120000001];
int n, top_data, ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout)
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		int c;
		scanf("%d %c", &num, &c);
		for (int i = 1; i <= num; i++) {
			data_mine[++top_data] = c;
		}
	}
	for (int i = 1, j = top_data; i <= top_data / 2; i++, j--) {
		if (data_mine[i] != data_mine[j]) {
			ans++;
		}
	}
	printf("%d\n", ans);
}