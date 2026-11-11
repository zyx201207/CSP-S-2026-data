#include<bits/stdc++.h>
#define rep(a,b) for(int i=(a); i<=(b); ++i)
#define per(a,b) for(int i=(b); i>=(a); ---i)
#define int long long
using namespace std;
const int MAXN = 0x3f3f3f3f;
const int N = 5e5 + 5;
int n, m, a[N], ans = 0;
int d[N], t, v;

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(1,n) cin >> a[i];
	
	sort(a+1,a+n+1);
	rep(2,n) d[i-1] = a[i] - a[i-1];
	
	bool ab = 1;
	rep(1,n-2){
		if(d[i]!=d[i+1]){
			ab = 0;
			break;
		}
	}
	
	if(!ab){
		for(int i=1; i<n; ++i){
			t = 0; v = m;
			for(int j=i; j<n; j++){
				t++;
				v -= t*d[j];
				if(v < (t+1)*d[j+1]) break;
			}
			ans = max(ans, t);
		}
		ans++;
		cout << ans;
	}
	else{
		t = 0; v = m;
		for(int j=1; j<n; j++){
			t++;
			v -= t*d[j];
			if(v < (t+1)*d[j+1]) break;
		}
		ans = t+1;
		cout << ans;
	} 
	return 0;
}
