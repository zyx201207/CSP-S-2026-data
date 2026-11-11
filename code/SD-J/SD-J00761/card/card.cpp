#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[300005], a[500005];
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int p[300005], top;
	for(int i = 0; i < n; i++) {
		top = 0;
		for (int j = i; j < n; j++) {
			for (int k = 0; k < top; k++) {
				if (p[k] == a[j]) {
					top = k;
					break;
				}
			}
			p[top++] = a[j];
		}
		for (int j = 0; j < top; j++) {
			cnt[p[j]]++;
		}

	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", cnt[i]);
	}
	
	return 0;
} 
