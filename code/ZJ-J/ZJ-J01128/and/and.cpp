#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 2;
int a[MAXN];
bool bits[MAXN][30 + 1];

int read() {
	int v = 0;
	char ch;
	while((ch = getchar()) && isdigit(ch)) {
		v = v * 10 + ch - '0';
	}
	return v;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	n = read(), m = read();

	vector<int> bit_cnt(30 + 1, 0);
	
	int max_bit = 0;
	int all_and = -1;
	for (int i = 0; i < n; i++) {
		a[i] = read();
		if (all_and == -1) all_and = a[i];
		else all_and &= a[i];
	}//O(n)
	
	if (m == n) {
		printf("%d", all_and);
		return 0;
	}
	
	sort(a, a + n, greater<int>()); //O(n log n)

	for (int i = 0; i < n; i++) {
		int x = a[i];
		int k = 1;
		while(x) {
			if (x & 1) bits[i][k] = true, bit_cnt[k]++;
			++k, x >>= 1;
		} 
		max_bit = max(k - 1, max_bit);
	}//O(30n)
	
	int cnt0 = 0;
	for(int i = 1; i <= max_bit; i++) {
		if (bit_cnt[i] >= m) cnt0++;
	}
	
	if (cnt0 == 0) {
		cout << 0;
		return 0;
	}
	
	vector<bool> chosen(n, false);
	long long ans = 0, cnt = 0;
	for (int b = max_bit; b >= 1; b--) {
		if (bit_cnt[b] < m) continue;
		for (int i = 0; i < n; i++) {
			if (chosen[i] || !bits[i][b]) continue;
			
			if (ans == 0) ans = a[i];
			else ans &= a[i];
			++cnt;
			chosen[i] = true;
			if (cnt >= m) break;
		}
		if (cnt >= m) break;
	}
	printf("%d", ans);
	
	return 0;
}
