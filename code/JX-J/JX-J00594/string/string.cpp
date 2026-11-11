#include <bits/stdc++.h>
#define int long long
#define IO freopen("string.in","r",stdin),freopen("string.out","w",stdout)
#define ll long long
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

int n;
int a[MAXN];
char c[MAXN];
int ans;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	IO;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		cin >> c[i];
	}
	
	for(int l = 1,r = n;l < r;){
		if(a[l] <= a[r]){
			if(c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			a[l] = 0;
		}
		else{
			if(c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			a[r] = 0;
		}
		if(a[l] == 0) l ++;
		if(a[r] == 0) r --;
	}
	
	cout << ans;
	return 0;
}

//start time: 16:30
//end time: 20:00

//CSP-J 2026 JX
//do not forget to add freopen!

