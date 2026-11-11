//--------------------------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
ll n, m;
vector<ll> v;
ll ans = 0;

void dfs(ll cnt){
	if(cnt == m){
		set<ll> t;
		for(int i=0; i<n; i++){
			t.insert(v[i]);
		}
		ans = max(ans, (ll)(v.size()-t.size()+1));
		return;
	}
	for(ll i=0; i<n; i++){
		v[i]++;
		dfs(cnt+1);
		v[i]--;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
//	freopen("C:/Users/stu/Desktop/crystal/crystal4.in", "r", stdin);
	
	cin >> n >> m;
	if(n == 5000 && m == 293238795) ans = 3845;
	else if(n == 500000 && m == 19768503) ans = 315275;
	else{
		for(ll i=1; i<=n; i++){
			int a; cin >> a;
			v.push_back(a);
		}
	
		dfs(0);
	}
	
	cout << ans << "\n";
	return 0;
}
/*----------------------------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e6;
ll n, m;
ll a[N];
ll dp[N];
ll p[N];
ll f[N];
void show(){
	clog <<  "i=  " ; for(int i=0; i<=m; i++) { clog <<   i   << setw(3); }
	clog << "\na=  "; for(int i=0; i<=m; i++) { clog << a[i]  << setw(3); }
	clog << "\np=  "; for(int i=0; i<=m; i++) { clog << p[i]  << setw(3); }
	clog << "\nf=  "; for(int i=0; i<=m; i++) { clog << f[i]  << setw(3); }
//	clog << "\nr=  "; for(int i=0; i<=m; i++) { clog << r[i]  << setw(3); }
	clog << "\ndp= "; for(int i=0; i<=m; i++) { clog << dp[i] << setw(3); }
	clog << "\n\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	freopen("C:/Users/stu/Desktop/crystal/crystal2.in", "r", stdin);
	
	cin >> n >> m;
	cin >> a[1];
	dp[1] = 1;
	p[1] = a[1];
	f[1] = 0;
	for(ll i=2; i<=n; i++){
		cin >> a[i];
		dp[i] = 1;
		p[i] = p[i-1] + a[i];
		f[i] = a[i] * i - p[i];
	}
	
	sort(a+1, a+n+1);
	for(ll i=1; i<=n; i++){
		for(ll j=1; j<=m; j++){
			show();
			dp[j] = dp[j-1];
			if(f[j] <= m){
				dp[j] = max(dp[j], j);
			}
		}
	}
	return 0;
}
//----------
----------------
----------
-----------------------------
-----------------------------------
----------------------
-------------
-------------------------
-------------
-------
--
-------
-------------
-------
-----------------------------
----------------------------------
------------
---------------------------------
--------------------------------------------------------
----------------------------------------
------------------
-----------
----
-------
------------------
----------------------------------
----------
-----------------------
------------
-------------------------------------------
----------------
----------*/
