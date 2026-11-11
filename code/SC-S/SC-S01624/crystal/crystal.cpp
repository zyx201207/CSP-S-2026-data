#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
int n,m;
int ans = 1;
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 2;i <= n;i++){
		int l = 1,r = i - 1,ac = -1;
		while(l <= r){
			int mid = l + r >> 1;
			if((i - 1 - mid + 1) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m){
				ac = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		if(ac != -1)
			ans = max(ans,i - ac + 1);
	}
	cout << ans;
	return 0;
}
//14:50