#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
long long n, m;
long long a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool pd1 = 1, pd2 = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != i) pd1 = 0;
		if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			pd2 = 0;
	} 
	if(pd1){
		int d = 1, ans = 0;
		while(m >= 0){
			m -= d;
			if(m >= 0) ans++;
			m -= d; 
			if(m >= 0) ans++;
		}
		cout << min(n, ans + 1);
		return 0;
	}
	if(pd2){
		long long d = a[n] - a[n - 1], ans = 0;
		while(m >= 0){
			m -= d;
			if(m >= 0) ans++;
			m -= d; 
			if(m >= 0) ans++;
		}
		cout << min(n, ans + 1);
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	a[0] = -0x3f3f3f3f3f3f3f3f, a[n + 1] = 0x3f3f3f3f3f3f3f3f;
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		int l = i - 1, r = i + 1;
		long long cnt = m;
		int ans = 0;
		while(cnt >= 0){
			int s1 = a[i] - a[l], s2 = a[r] - a[i];
			if(s1 <= s2) cnt -= s1, l--;
			else cnt -= s2, r++;
			if(cnt >= 0) ans++;
			//cout << s1 << " " << s2 << "\n";
		}
		///if(ans == 4999) {
		//	for(int i = 1; i <= 1000; i++) cout <<"\n";
		//}
		maxn = max(maxn, ans);
	}
	cout << maxn + 1;
	return 0;
}
