#include <bits/stdc++.h>

using namespace std;
int maxx = -1e9;
int m, n;
int a[100011];
int maxn = -1e9;
int solve (){
	for (int l = 1,r = 1;l <= n,r <= n;r ++){
		 maxn = max(maxn, a[l]&a[r]);
		if (r == n){
			l ++;
			r = l;
		}
	}
	return maxn;
}

int main (){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
		maxx = max (maxx, a[i]);
	}
	sort (a + 1, a + n + 1);
	if (m == 1) cout << maxx <<endl;
	if (m == 2) cout << solve() << endl;
	return 0;
}
