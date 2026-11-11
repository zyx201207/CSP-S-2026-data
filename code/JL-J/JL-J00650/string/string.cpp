#include<bits/stdc++.h>
#define int long long
#define QwQ 0
#define debug cout << "!!!" << "\n";
using namespace std;
int n;
int a[200010], cnt;
char c[200010];
int sum[200010], pre[200010];
int pret[200010][30];
int ans;
int ef1(int x){
	int l = 1, r = n, res = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(pre[mid] + 1 > x){
			res = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return res;
}
int ef2(int x){
	int l = 1, r = n, res = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(pre[mid] + 1 > x){
			res = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return res + 1;
}
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		cnt += a[i];
	}
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = n; i >= 1; i--){
		pre[i] = pre[i + 1] + a[i];
		for(int j = 0; j < 26; j++){
			pret[i][j] = pret[i + 1][j] + a[i] * ((c[i] - 'a') == j);
		}
	}
	for(int i = 1; i <= n; i++){
		int l = sum[i - 1] + 1, r = sum[i];
		int x = ef1(l);
		int y = ef2(r);
		int res = (pre[y] - pre[x]) - (pret[y][c[i] - 'a'] - pret[x][c[i] - 'a']);
		res += (r - pre[y]) * (c[y - 1] != c[i]) + (pre[x] - l + 1) * (c[x] != c[i]);
		ans += res;
	}
	cout << ans / 2 << '\n';
	return QwQ;
}