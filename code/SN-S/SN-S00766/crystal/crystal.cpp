#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m;
long long a[N];
long long mx = -1e12 - 10;
long long mn = 1e12 + 10;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}  
	bool f1 = true, f2 = true;//f1 => 等差 f2 => 全相等 
	for (int i = 2; i < n; i++){
		if (a[i] - a[i-1] != a[i+1] - a[i]) f1 = false;
		if (a[i] != a[i-1] || a[i] != a[i+1]) f2 = false;
	}
	if (f2){
		cout << n << "\n";
		return 0;
	}
	if (f1){
		int c = abs(a[2] - a[1]);
		int cut = 1, ans = 1;
		if (m >= (n * (n + 1)) / 2 * c){
			cout << n << "\n";
			return 0;
		}
		else {
			while (m >= cut * c){
			    m -= cut * c;
			    ans++;
			    cut++;
		    }
		    cout << ans << "\n";
		    return 0;
		}
	}
	sort(a+1,a+n+1);
	int ans = 1;
	for (int i = mn; i <= mx; i++){
		int now;
		for (int j = 1; j <= n; j++) if (a[j] <= i) now = j;
		int nowm = m;
		int nowans = 0;
		while (nowm >= i - a[now] && i >= a[now] && now >= 1){
			nowm -= (i - a[now]);
			nowans++;
			now--;
		}
		//cout << "now=" << now << ";i=" << i << ";nowans=" << nowans << ";" << "\n";
		ans = max(ans, nowans);
	}
	cout << ans << "\n";
	return 0;
} 
