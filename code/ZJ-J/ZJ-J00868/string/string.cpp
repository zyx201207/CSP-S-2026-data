#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010; 
int n, a[N], c[N], gcd, st[N], sum, ans;
int find(int x) {
	int l = 1, r = n, ans, mid;
	while(l <= r) {
		mid = l + r >> 1;
		if(x >= st[mid]) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		char ch;
		cin >> a[i] >> ch;
		c[i] = ch - 'a';
		if(!gcd) gcd = a[i];
		else gcd = __gcd(a[i], gcd);
	}
	st[1] = 1;
//	cout << gcd << endl;
	for(int i = 1; i <= n; i++) {
		a[i] /= gcd;
		if(i >= 2)st[i] = st[i - 1] + a[i - 1]; 
		sum += a[i];
	}
//	for(int i = 1; i <= n; i++) {
//		cout << st[i] << " ";
//	}cout << endl;
	int i = 1, j = 1, k = sum;//i:当前所在块，j:当前位置，k:右边位置 
	while(j <= k) {
//		if(i > (n + 1) / 2 && j > (sum + 1) / 2) break;
		int an = find(k);
		if(an == i) break;
		int len1 = st[i + 1] - j, len2 = k - st[an] + 1;
//		cout << i << " " << j << " " << an << " " << len1 << " " << len2 << "\n";
		if(c[i] != c[an]) ans += min(len1, len2);
		j += min(len1, len2);
		k -= min(len1, len2);
		while(j >= st[i + 1]) i++;
//		if(len1 == len2) j++;
	} 
//	cout << ans << endl;
	//答案要乘上gcd啊awa 
	cout << ans * gcd;
	return 0;
}
//希望没有bug 
