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

const ll N = 500022;
ll lis[N], sm[N];
ll n, m, p, res = 1;

int main(){
	freopen("crystal.in" ,"r", stdin);
	freopen("crystal.out","w", stdout);
	n = read();
	m = read();
	fff(i, 1, n){
		lis[i] = read();
	}
	sort(lis + 1, lis + 1 + n);
	fff(i, 1, n){
		sm[i] = sm[i - 1] + lis[i];
		while(1){
			ll s = sm[i] - sm[p];
			ll ned = (i - p) * lis[i];
			if(s + m < ned){
				p++;
			} else {
				break;
			}
		}
		res = max(res, i - p);
	}
	cout << res <<'\n';
	return 0;
}

/*

5 5
1 2 4 8 9

3

---

5 8
-3 -1 2 2 7

4

feropen("hub.in" ,"r", stdin);

*/

// RNZAF BIE-4+ BIE-4 BIE-4 [38]
// Im k_mod_zero(1412412) , a kards player
