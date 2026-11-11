#include <bits/stdc++.h>
using namespace std;

int n, m, x = -1, tc, tb;
int a[200010], ans[50];
int bt[200010], b[200010][40], c[200010][40], ct[200010];
int fff;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		int l = a[i];
		while(l > 0) {
			b[i][++bt[i]] = l % 2;
			l /= 2;
		}
		for(int j = 1; j <= bt[i]; j++)
			if(b[i][j])
				ans[j]++;
	}
	for(int i = 35; i >= 1; i--)
		if(ans[i] >= m) {
			x = i;
			break;
		}
	if(x == -1) {
		printf("0\n");
		return 0;
	}
	int uu = 1;
	for(int i = 1; i < x; i++)
		uu *= 2;
	fff += uu;
	for(int i = 1; i <= n; i++)
			if(b[i][x]) {
				++tc;
				for(int j = 1; j <= bt[i]; j++)
					c[tc][++ct[tc]] = b[i][j];
			}
			
			
			
			
	for(int t = x - 1; t >= 1; t--) {
		memset(ans, 0, sizeof(ans));
		memset(b, 0, sizeof(b));
		memset(bt, 0, sizeof(bt));
		tb = 0;
	for(int i = 1; i <= tc; i++) {
		tb++;
		for(int j = 1; j <= ct[i]; j++)
			b[tb][++bt[tb]] = c[i][j];
	}
	memset(c, 0, sizeof(c));
	memset(ct, 0, sizeof(ct));
	tc = 0;
	for(int i = 1; i <= tb; i++)
		for(int j = 1; j <= bt[i]; j++)
			if(b[i][j])
				ans[j]++;
	x = -1;
	for(int i = t; i >= 1; i--)
		if(ans[i] >= m) {
			x = i;
			break;
		}
	if(x != -1) {
	int uu = 1;
	for(int i = 1; i < x; i++)
		uu *= 2;
	fff += uu;
	for(int i = 1; i <= tb; i++)
			if(b[i][x]) {
				++tc;
				for(int j = 1; j <= bt[i]; j++)
					c[tc][++ct[tc]] = b[i][j];
			}
	}
	}
	printf("%d\n", fff);
	return 0;
}
