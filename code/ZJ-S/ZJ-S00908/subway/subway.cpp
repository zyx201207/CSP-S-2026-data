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
ll lis[N], w[N], k[N];
ll n, m, c__, d, q;

struct edge{
	ll t, c;
	edge(){}
	edge(ll t_, ll c_): t(t_), c(c_) {}
};

vector<edge>ed[N];

ll mp[533][533];

int main(){
	freopen("subway.in" ,"r", stdin);
	freopen("subway.out","w", stdout);
	c__ = read();
	n = read();
	m = read();
	d = read();
	q = read();
	fff(i, 1, m){
		w[i] = read();
	}
	fff(i, 1, n){
		k[i] = read();
		fff(j, 1, k[i]){
			ll a = read(), t = read();
			ed[a    ].push_back(edge(m + i, t));
			ed[m + i].push_back(edge(a    , t));
		}
	}
	memset(mp, 0x3f, sizeof(mp));
	fff(i, 1, m){
		for(auto f: ed[i]){
			for(auto g: ed[i]){
//				cout << i <<"= "<< f.t <<' '<< f.c <<' '<< g.t <<' '<< g.c <<'\n';
				if(f.t == g.t){
					mp[f.t - m][g.t - m] = 0;
					continue;
				}
				mp[f.t - m][g.t - m] = min(mp[f.t - m][g.t - m], f.c + g.c);
			}
		}
	}
//	fff(i, 1, n){
//		fff(j, 1, n){
//			cout << i <<' '<< j <<"= "<< mp[i][j] <<'\n';
//		}
//	}//--------------------------------------------------------------------------------------------------------------------------ck
	fff(k, 1, n){
		fff(i, 1, n){
			fff(j, 1, n){
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
			}
		}
	}
	fff(_, 1, q){
		ll x = read(), y = read();
		ll res = 0x3f3f3f3f3f3f;
		for(auto f: ed[x]){
			for(auto g: ed[y]){
				res = min(res, w[x] + w[y] + f.c + g.c + mp[f.t - m][g.t - m]);
//				cout << f.t <<' '<< g.t <<"= "<< mp[f.t - m][g.t - m] <<' '<< f.c <<' '<< g.c <<'\n';
			}
		}
		cout << res <<'\n';
	}
	return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17


feropen("hub.in" ,"r", stdin);

*/

// RNZAF BIE-4+ BIE-4 BIE-4 [38]
// Im k_mod_zero(1412412) , a kards player
