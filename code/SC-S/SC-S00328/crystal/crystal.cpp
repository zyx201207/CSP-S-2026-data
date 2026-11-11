#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

long long n, a[N], m, ans, s[N], last = 1;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i ++ ){
		s[i] = s[i - 1] + a[i];
		while (s[i] - s[last - 1] + m < a[i] * (i - last + 1)) last ++ ;
		ans = max(ans, i - last + 1);
	}
	
	cout << ans;
	
	return 0;
}