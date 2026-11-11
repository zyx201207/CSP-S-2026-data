#include <bits/stdc++.h>
#include <string>
using namespace std;
int n, a[200010], lst;
long long al, ans = 0;
char c[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		al += a[i];
	}
	lst = n;
	for(int i = 1; i <= n && al > 0; i++){
		while(a[i] >= a[lst] && al > 0){
			if(c[i] != c[lst]) ans += a[lst];
			a[i] -= a[lst];
			al -= (2 * a[lst]);
			a[lst] = 0;
			lst--;
		}
		if(a[i] == 0) continue;
		if(c[i] != c[lst]) ans += a[i];
		a[lst] -= a[i];
		al -= (2 * a[i]);
		a[i] = 0;
	}
	cout << ans;
	return 0;
}
