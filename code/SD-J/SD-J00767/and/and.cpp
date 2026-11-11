#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int cnt[45], ans = 0, a[N], sum = 0;
int b[N];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k = 1, res = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		int l = 0, x = a[i];
		while(x){
			if(x & 1)cnt[l]++;
			x >>= 1;
			l++;
		}
		l--;
		if(cnt[l] >= m && k < l){
			k = l;
		}
	}
	for(int i = 1; i <= n; i++){
		int l = 0, x = a[i];
		while(x && l <= k){
			if(x & 1)b[i] += 1 << l;
			x >>= 1;
			l++;
		}
	}
	sort(b + 1, b + 1 + n);
	for(int i = n; i >= 1 && sum < m; i--){
		int x = b[i];
		if(ans == 0)ans = x;
		else ans = ans & x;
		sum++;
	}
	cout << ans;
	return 0;
}
