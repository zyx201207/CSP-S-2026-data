#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10; 
long long n, m, flag, l, r, lid, rid, ans, a[N], q[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i] >> c[i], q[i] = q[i - 1] + a[i];
	m = q[n];
	if (m & 1){
		for (int i = 1; i <= n; i ++){
			if (q[i] >= (m + 1) / 2){
				l = q[i - 1];
				r = q[i] + 1;
				if (l + r > m + 1){
					r = m + 1 - l;
					lid = i - 1, rid = i;
				}
				else if (l + r < m + 1){
					l = m + 1 - r;
					lid = i, rid = i + 1;
				}
				else lid = i - 1, rid = i + 1;
				break; 
			}
		}
	}
	else {
		for (int i = 1; i <= n; i ++){
			if (q[i] >= m / 2){
				l = m / 2, r = m / 2 + 1;
				if (q[i] != m / 2){
					l = q[i - 1];
					r = q[i] + 1;
					if (l + r > m + 1){
						r = m + 1 - l;
						lid = i - 1, rid = i;
					}
					else if (l + r < m + 1){
						l = m + 1 - r;
						lid = i, rid = i + 1;
					}
					else lid = i - 1, rid = i + 1;
				}
				else lid = i, rid = i + 1;
				break; 
			}
		}
//		cout << l << " " << r << " " << lid << " " << rid << '\n';
	}
	while (1){
		long long nl = q[lid - 1] + 1;
		long long nr = q[rid];
		if (l - nl > nr - r){
			nl = l + r - nr;
			if (c[lid] != c[rid]) ans += nr - r + 1;
			l = nl - 1, r = nr + 1;
			rid += 1;
		}
		else if (l - nl < nr - r){
			nr = l + r - nl;
			if (c[lid] != c[rid]) ans += nr - r + 1;
			l = nl - 1, r = nr + 1;
			lid -= 1;
		}
		else {
			if (c[lid] != c[rid]) ans += nr - r + 1;
			l = nl - 1, r = nr + 1;
			lid -= 1, rid += 1;
		}
		if (lid <= 0 || rid > n || l <= 0 || r > m) break;
	}
	cout << ans;
	return 0;
}
