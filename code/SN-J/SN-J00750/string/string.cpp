//齐君豪 西安市含光中学 SN-J00750
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200010;

int n;
int a[N];
ll s[N], ans;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i], s[i] = s[i - 1] + a[i];
	ll l = 0, r = 0;
	int id_l = 1, id_r = n;
	int sy_l = 0, sy_r = 0;
	for(int i = 1; i <= n; i++) {
		id_l++;
		if(l + a[i] <= ((s[n] - 1) / 2) + 1)
			l += a[i];
		else l = ((s[n] - 1) / 2) + 1, sy_l = a[i] - (l - s[i - 1]);
		while(r < l) {
			if(sy_r > 0) {
				if(r + sy_r <= l) {
					r += sy_r;
					if(c[id_r] != c[i])
						ans += sy_r;
					sy_r = 0;
				} else {
					sy_r -= (l - r);
					if(c[id_r] != c[i])
						ans += (l - r);
						r = l;
					break;
				}
			} else {
				if(r + a[id_r] <= l) {
					r += a[id_r];
					if(c[id_r] != c[i])
						ans += a[id_r];
				} else {
					sy_r = a[id_r] - (l - r);
					if(c[id_r] != c[i])
						ans += l - r;
					r = l;
					break;
				}
			}
			id_r--;
		}
	}
	printf("%lld\n", ans);
	return 0;
} 
