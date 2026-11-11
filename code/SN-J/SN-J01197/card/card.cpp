#include <bits/stdc++.h>
using namespace std;

int n, a[200010], ans[300067] = {0}, p[300067], m;
	int top = 0;
bool f(int i) {
	int f = 1;
	for (int j = 0; j <= top; j ++) {
		if(p[i] == p[j]) f = 0;
	}
	return f;
}

int t(int i) {
	for (int j = 0; j < i; j ++) {
		if(p[i] == p[j]) return i - j;
	}
	return 0;
}

void io(int i) {
	for (int j = 1; j <= top; j ++) {
		ans[j]  ++;
	}
}

	
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		io(i);
		top ++;
		p[top] = a[i];cout << f[i] << " ";
		if (!f(i)) {
			top -= t(i);
		} 
		
	}
	for (int i = 1; i < m; i ++) {
		printf("%d\n", ans[i]);
	}printf("%d", n);
	
	return 0;
}
