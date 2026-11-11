#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int t[200005];
int b[200005], cur;
int fnd(int k){
	for(int i = 1; i <= cur; i++){
		if(b[i] == k) return i;
	}
	return -1;
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cur = 0;
		for(int j = i; j <= n; j++){
			int fn = fnd(a[i]);
			if(fn == -1) b[++cur] = a[i];
			else {
				cur = fn;
			}
		}
		if(fnd(i) != -1) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
