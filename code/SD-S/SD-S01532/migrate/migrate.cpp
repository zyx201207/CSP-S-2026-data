#include <bits/stdc++.h>

using namespace std;
const int N = 2e6+10;
int n;
long long x[N], ans, d;

long long llc,ll;
void check(int l,int r,long long way){
	if (way > ll) return; 
	if (l == r){
		if (way == ll){
			llc++;
		}
		if (way < ll){
			ll = way;
			llc = 1;
		}
		return;	
	} 
	for (int nxt = l+1;nxt <= r && x[nxt]-x[l] <= d;nxt++){
		check(nxt,r,way+1);
	}
	return;
}

void calc(){
	ans = 0;
	for (int l = 1;l < n;l++){
		for (int r = l+1;r <= n && x[r]-x[r-1] <= d;r++){
			if (x[r]-x[l] <= d) continue;
			llc = 0, ll = 1e9+10;
			check(l,r,0);
			if (llc == 2) ans++;
		}
	}
	cout << ans << '\n';
}

void calcA(){
	if (d < x[2]-x[1]) {cout << 0 << '\n'; return;}
	ans = 0;
	for (int l = 1;l < n;l++){
		for (int r = l+1;r <= n && x[r]-x[r-1] <= d;r++){
			llc = 0, ll = 1e9+10;
			check(l,r,0);
			if (llc == 2) ans++;
		}
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t,c;
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		if (n == 1) {cout << 0 << '\n'; continue;}
		for (int i = 1;i <= n;i++){
			cin >> x[i];
		}
		if (11 <= c && c <= 12) calcA();
		else calc();
	}
	
	ans = 0;
	return 0;
}

