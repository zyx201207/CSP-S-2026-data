#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5e5+5;
const int N = 505;
const ll inf = 1e18;
int testnumber;
inline ll read(){
	ll x = 0;char c = getchar();
	while(c < '0'||c > '9'){
		c = getchar();
	}
	while(c >= '0'&&c <= '9'){
		x = (x<<1) + (x<<3) + int(c-'0');
		c = getchar();
	}
	return x;
}
void write(ll x){
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}
struct node{
	int pos;
	ll t;
};
int n,m,d,q;
ll w[M];
ll dis[N][N];
int k[N];
vector<node> a[N];
vector<node> b[M];
int np;ll nt;
int s,t;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	testnumber = read();
	n = read();m = read();d = read();q = read();
	for(int i = 1;i <= m;i++) w[i] = read();
	for(int i = 1;i <= n;i++){
		k[i] = read();
		for(int j = 1;j <= k[i];j++){
			np = read();
			nt = read();
//			a[i].push_back({np,nt});
			b[np].push_back({i,nt});
		}
	}
	for(int i = 1;i <= m;i++){
		int k = b[i].size();
		for(int j = 0;j < k;j++){
			for(int o = 0;o < k;o++){
				if(j == o) continue;
				s = b[i][j].pos;
				t = b[i][o].pos;
				dis[s][t] = b[i][j].t+b[i][o].t;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j) continue;
			if(!dis[i][j]) dis[i][j] = inf;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				if(i == j||j == k||i == k) continue;
				dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout << dis[i][j] << " ";
//		}
//		cout << '\n';
//	}
	while(q--){
		cin >> s >> t;
		ll ans = inf;
		int ks = b[s].size();
		int kt = b[t].size();
		int ps,pt;
		for(int i = 0;i < ks;i++){
			for(int j = 0;j < kt;j++){
				ans = min(ans,w[s]+w[t]+dis[b[s][i].pos][b[t][j].pos]+b[s][i].t+b[t][j].t);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

