#include <bits/stdc++.h>
#define ll long long
#define int long long
#define IO freopen("and.in","r",stdin),freopen("and.out","w",stdout)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pqu priority_queue

#define lowbit(x) ((x) & (-x))

using namespace std;

ll qpow(ll a,ll x,ll mod){ll res = 1;while(x){if(x & 1){res = res * a % mod;}x >>= 1ll;a = a * a % mod;}return res;}

const int MAXN = 200010;
int n,k;
int a[MAXN];
int ans;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	IO;
	cin >> n >> k;
	vector <int> p,q;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		p.pb(a[i]);
	}
	
	for(int i = 30;i >= 0;i --){
		int j = (1LL << i);
		for(auto m : p){
			if(m & j){
				q.pb(m);
			}
		}
		
		if((ll)q.size() >= k){
//			cout << (ll)q.size() << ' ' << k << '\n';
//			for(auto m : q) cout << m << ' ';
//			cout << '\n';
			ans += j;
			p = q;
		}
		q.clear();
	}
	
	cout << ans << '\n';
	return 0;
}

//start time: 16:30
//end time: 20:00

//CSP-J 2026 JX
//do not forget to add freopen!

/*
5 3
31 3 1 15 7
*/
