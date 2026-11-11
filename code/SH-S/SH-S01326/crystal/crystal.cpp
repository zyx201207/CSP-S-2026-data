#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+7;

int n, ans;
ll m, a[N], dediff[N], pfx[N];
/*
vector <int> val[N];

int solve(int l, int r) {
	if(r == l) {
		return 0;
	}
	if(r-l == 1 && a[r]-a[l] <= m) {
		//ans = max(ans, 2);
		val[l][r] = val[r][l] = a[r]-a[l];
		cout << "Renew on " << l << "-" << r << " : " << a[r]-a[l] << ".\n";
		return val[r][l];
	}
	int mid = (l+r) >> 1;
	int lv, rv;
	bool flag = false;
	if(val[l][mid] != 0) {
		flag = true;
		lv = val[l][mid];
	}
	if(val[mid+1][r] != 0) {
		flag = true;
		rv = val[mid+1][r];
	}
	if(!flag)
		lv = solve(l, mid), rv = solve(mid+1, r);
	val[l][r] = val[r][l] = lv+rv+(r-mid+1)*(a[r]-a[mid]);
	if(lv == -1 && rv != -1)
		return rv;
	if(lv != -1 && rv == -1)
		return lv;
	if(lv == -1 && rv == -1)
		return -1;
	if(lv+rv+(r-mid)*(a[r]-a[mid]) <= m) {
		cout << "Renew on " << l << "-" << r << " : " << lv+rv+(r-mid+1)*(a[r]-a[mid]) << ".\n";
		return lv+rv+(r-mid)*(a[r]-a[mid]);
	}
	return -1;
}*/

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	bool A = true, B = true;
	
	//ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(i != a[i])
			A = false;
		if(i >= 3 && a[i-1]-a[i] != a[i-2]-a[i-1])
			B = false;
	}
	for(int i = 1; i <= n; i++) {
		dediff[i] = a[n]-a[i];
		pfx[i] = pfx[i-1]+dediff[i];
		//val[i].resize(n+1);
	}
	for(int i = n; i >= 1; i--) {
		if(pfx[i] <= m) {
			ans = i;
			break;
		}
		pfx[i-1] -= (i-1)*dediff[i-1];
	}
	if(!A && !B) {
		for(int i = n; i >= 1; i--) {
			for(int j = 1; j <= i; j++) {
				if(pfx[i]-pfx[j-1] <= m)
					ans = max(ans, i-j+1);
			}
		}
	} else {
		for(int i = n; i >= 1; i--) {
			if(pfx[i] <= m) {
				ans = i;
				break;
			}
		}
	}
	/*
	for(int i = 2; i < n; i++) {
		if(solve(1, i) != -1)
			ans = max(ans, i);
		if(solve(i+1, n) != -1)
			ans = max(ans, n-i);
	}
	*/
	cout << ans << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
