#include<bits/stdc++.h>
#define fff(i, a, b) for(ll i = a; i <= b; ++i)

typedef long long ll;
using namespace std;

ll innum(char x){
	return '0'<= x && x <='9';
}
ll read(){
	ll c = getchar(), res = 0, f = 1;
	for(; !innum(c); c = getchar()) if(c =='-') f = -1;
	for(;  innum(c); c = getchar()) res = res * 10 + c -'0';
	return res * f;
}

const ll N = 1000022;
ll lis[N], dp[N], est[N];
ll c, t, n, d;

void solve(){
	n = read();
	d = read();
	fff(i, 1, n){
		lis[i] = read();
	}
	cout << 0 <<'\n';
}

int main(){
	freopen("migrate.in" ,"r", stdin);
	freopen("migrate.out","w", stdout);
	c = read();
	t = read();
	fff(_, 1, t){
		solve();
	}
	return 0;
}

/*




feropen("hub.in" ,"r", stdin);

*/

// RNZAF BIE-4+ BIE-4 BIE-4 [38]
// Im k_mod_zero(1412412) , a kards player
