#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long a[N], q[N], num[N], n, m;
bool check_A(){
	for (long long i = 2; i <= n; i++) if (a[i - 1] > a[i]) return false;
	return true;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	if (check_A()){
		a[0] = a[1];
		for (long long i = 1; i <= n; i++)
			if (a[i] != a[i - 1]) cout << i - 1 << " ";
		cout << n;
	} else {
		for (long long i = 1; i <= n; i++){
			long long l = 1, r = 0;
			for (long long j = i; j <= n; j++){
				for (long long k = l; k <= r; k++){
					if (q[k] == a[j]){
						r = k - 1;
						break;
					}
				}
				q[++r] = a[j];
			}
			for (long long j = l; j <= r; j++) num[q[j]]++;
		}
		for (long long i = 1; i <= m; i++) cout << num[i] << " ";
	}
	return 0;
}