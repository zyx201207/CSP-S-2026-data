#include<bits/stdc++.h>
using namespace std;


int n, a[200001], b[200001];
long long L, ans = 0;
char s[200005], c[200005]; 

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d %c", &a[i], &s[i]);
	for (int i = 1; i <= n; i++) {
		b[i] = a[n - i + 1];
		c[i] = s[n - i + 1];
	}
	for (int i = 1; i <= n; i++)
		L += a[i];
	long long t = L / 2, i = 1, id = 1, j = 1, jd = 1;
	while(t) {
		if (s[id] != c[jd]) {
			if (a[id] > b[jd]) {
				ans += b[jd];
				jd++;
				j = 1;
				i += b[jd];
			}
			else {
				if (a[id] < b[jd]) {
					ans += a[id];
					id++;
					i = 1;
					j += b[id];
				}
				else {
					ans += a[i];
					id++;
					jd++;
					i = 1;
					i = 1;
				}
			}
		}
		else{
			i++, j++;
			if (i > a[id])
				id++, i -= a[id];
			if (j > b[jd])
				jd++, j -= b[jd];
		}	
		t--;
	}
	printf("%lld", ans);
	return 0;
}
