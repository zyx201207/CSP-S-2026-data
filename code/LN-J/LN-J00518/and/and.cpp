#include <bits/stdc++.h>
#define int long long int
#define st string
#define re return
using namespace std;
const int one = 200007;
const int two = 10001;
int n, m, a[one], cnt;
inline bool cmp (int x, int y) {
	re x > y;
}
signed main(){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	stable_sort (a, a + n, cmp);
	cnt = a[0];
	for (int i = 1; i < m; i++) cnt &= a[i];
	cout << cnt << endl;
	
	fclose (stdin);
	fclose (stdout);

	re 0;
}
