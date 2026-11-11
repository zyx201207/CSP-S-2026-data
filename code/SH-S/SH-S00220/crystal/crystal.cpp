#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int sum[500010];
bool check(int x){
	for(int i = 1;i <= n - x + 1;i++){
		if((a[i + x - 1] * x) - (sum[i + x - 1] - sum[i - 1]) <= m){
			return 1;
		}
	}
	return 0;
}
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1,r = n + 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1; 
		}
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
