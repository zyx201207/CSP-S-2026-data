#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 2;
int n,m;
int v[N + 2],sum[N + 2];

bool check(int x){
	for(int i = 1;i <= n - x + 1;i++){
		int ed = i + x - 1;
		int nsum = sum[ed] - sum[i - 1];
		int goal = v[ed] * x;
		int d = goal - nsum;
//		cout << nsum << '\\' << goal << ' ';
		if(d <= m) return true;
	}
	return false;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> v[i];
	}
	sort(v + 1,v + n + 1);
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + v[i];
	}
//	cout << (int)check(3);
//	cin >> n;
	int l = 1,r = n;
	int ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else r = mid - 1;
	}
	cout << ans;
	return 0;
}
