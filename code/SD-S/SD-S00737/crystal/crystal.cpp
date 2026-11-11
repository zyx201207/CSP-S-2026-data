#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
const int mod = 998244353;
int n,m;
int a[N],sum[N];

bool chk(int len){
	for(int i = len;i <= n;i++){
	    if(a[i] * len - sum[i] + sum[i - len - 1] <= m){
	    	return 1;
		}
	}
	return 0;
}

void sol(){
	//memset()
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];	
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <=n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1,r = n;
	int ans = 0;
	while(l <= r){
	    int mid = (l + r) >> 1;
		if(chk(mid)){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << "\n";
}

//#define LOCAL

signed main(){
	#ifndef LOCAL
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--){
		sol();
	}
	return 0;
}

