#include<bits/stdc++.h>
using namespace std;

int n, ans, tot;
long long m, a[500005], b[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a+1, a+1+n);
	
	b[1] = 0;
	b[2] = a[2] - a[1];
	for(int i = 3; i <= n; i++) {
		b[i] = b[i-1] + (a[i] - a[i-1]) * (i - 1 - tot);//加一位 
		if(b[i] > m) {
			ans = max(ans, i - 1 - tot);
			while(b[i] > m) b[i] -= (a[i] - a[++tot]); //删前面的 
			ans = max(ans, i - 1 - tot);
		}
	}
	if(ans == 0) cout << n << endl; 
	else cout << ans << endl;
	return 0;
} 
//b[i] 表示从 a[tot+1] 到 a[i] 所需操作步数 
//@DanseSolo姐姐可爱喵 /xin 