#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m; cin >> n >> m;
	vector<long long> a(n);
	for (long long i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(),a.end());
	long long res = 1;
	vector<long long> rec(n); rec[0] = 1;
	vector<long long> cos(n); cos[0] = 0;
	for (long long i = 1; i < n; i++){
		if (cos[i-1] + rec[i-1]*(a[i]-a[i-1]) <= m){
			rec[i] = rec[i-1] + 1;
			cos[i] = cos[i-1] + rec[i-1]*(a[i]-a[i-1]);
		} else {
			cos[i] = 0, rec[i] = 1;
			long long left = i-1;
			while (true){
				long long leftc = LLONG_MAX;
				if (left >= 0) leftc = a[i] - a[left];
				if (leftc + cos[i] <= m && leftc != LLONG_MAX) left--, rec[i]++, cos[i] += leftc;
				else break;
			}
		}
	}
	for (int i = 1; i < n; i++) res = max(res, rec[i]);
	cout << res;
	return 0;
}
/*
a1 a2 a3 a4 a5 a6 a7 a8 a9 a10
a3 - 3
a4 
*/