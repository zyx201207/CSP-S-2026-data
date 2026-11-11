#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, ml = 1;
int a[N], pre[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2;i <= n;i++){
		pre[i] = pre[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for(int l = 1, r = 1;l <= n;l++){
		r = max(r, l);
		int cnt = pre[r] - pre[l] - (a[r] - a[l]) * (l - 1);
		while(cnt <= m && r <= n){
			cnt += (r - l + 1) * (a[r + 1] - a[r]);
			r++;
		}
		ml = max(ml, r - l);
	}
	cout << ml;
	return 0;
}
