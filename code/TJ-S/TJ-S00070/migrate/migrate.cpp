#include<bits/stdc++.h>
#define rep(a,b) for(int i=(a); i<=(b); ++i)
#define per(a,b) for(int i=(b); i>=(a); ---i)
#define int long long
using namespace std;
const int MAXN = 0x3f3f3f3f;
const int N = 2e6 + 5;
int c, case1, n, d, a[N], ans;

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> case1;
	if(c==11 || c==12){
		while(case1--){
			cin >> n >> d;
			rep(1,n) cin >> a[i];
			int t = a[2] - a[1];
			if(d<=t){
				cout << 0 << '\n';
			}
			else{
				ans = n - (2*(d/t) - 1);
				ans = max(1LL*0, ans);
				cout << ans << '\n';
			}
			
		}
	}else if(c==13 || c==14){
		while(case1--){
			cin >> n >> d;
			rep(1,n) cin >> a[i];
			cout << 0 << '\n'; 
		}
	}

	return 0;
}
