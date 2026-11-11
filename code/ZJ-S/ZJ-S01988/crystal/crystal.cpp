#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	vector<int> d(n);
	for (int i = 0; i < n; i++){
		d[i] = a[n - 1] - a[i];
	}
	vector<int> s(n);
	s[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--){
		s[i] = s[i + 1] + d[i];
	}
	int maxn = 0;
	for (int i = 0; i < n; i++){
		int l = 0,r = i;
		int ans = i;
		while(l <= r){
			int mid = (r - l) / 2 + l;
			if ((s[mid] - s[i] - (i - mid) * d[i]) <= m){
				ans = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		maxn = max(i - ans + 1,maxn);
	}
	cout << maxn;
	return 0;
} 
