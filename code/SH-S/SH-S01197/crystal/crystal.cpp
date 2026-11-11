#include<bits/stdc++.h>
#define lower_bit(x) x&(-(x))
#define int long long
using namespace std;

int T;
int n, m, ans, a[500000 + 10], s[500000 + 10];

bool check(int x, int u){
//	cout << a[u] * (u - x + 1) - s[u] + s[x - 1] <<"\n";
	if(a[u] * (u - x + 1) - s[u] + s[x - 1] <= m)return 1;
	else return 0;
}

void solve(){
	cin>>n>>m;
	ans=-1;
	
	for(int i = 1; i <= n; i++)cin>>a[i];
	
	sort(a+1, a+n+1);
	
	for(int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 1, r = i;
		
		while(l < r){
			int mid = (l + r) >> 1;
			if(check(mid , i))r = mid;
			else l = mid + 1;
//			cout<< i << " " << l << " " << r << "\n";
		}
		
		ans = max(ans, i - l + 1);
	}
	
	cout << ans << "\n";
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
//	cin>>T;
	T=1;
	
	while(T--){
		solve();	
	}
}
