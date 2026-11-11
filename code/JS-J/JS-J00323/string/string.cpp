#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, a[N], sum, ans;
char c[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int p1 = 1, t1 = 0, p2 = 1, t2 = 0;
	while(p1 != n - p2 + 1 && p1 <= (n + 1) / 2 && p2 <= (n + 1) / 2 && t1 < sum / 2 && t2 < sum / 2){
		int len = min(max(a[p1] + t1, a[n - p2 + 1] + t2), sum / 2) - max(t1, t2);
//		cout << p1 << ' ' << p2 << ' ' << a[p1] << ' ' << a[n - p2 + 1] << ' ' << t1 << ' ' << t2 << ' ' << len << endl;
		if(c[p1] != c[n - p2 + 1]) ans += len;
		if(a[p1] + t1 > a[n - p2 + 1] + t2) p2++, t2 += len;
		else if(a[p1] + t1 > a[n - p2 + 1] + t2) p1++, t1 += len;
		else p1++, p2++, t2 += len, t1 += len;
	}
	cout << ans;
	return 0;
}
