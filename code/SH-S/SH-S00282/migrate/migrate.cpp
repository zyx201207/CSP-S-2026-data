#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAXN = 2e6 + 5;
ll c, t, n;
ll D, x[MAXN], d[MAXN], cnt[MAXN];
ll d2[MAXN][2], len[MAXN], f[MAXN];
vector<int> e[MAXN];//index of ranges that starts with e[i][j] and ends with i
struct node{ll v, w;};
struct cmp{	bool operator() (const node a, const node b) const {return a.w > b.w;}};
void solve(){
	cin >> n >> D;
	for(int i = 1; i <= n; i++)e[i].resize(0);
	for(int i = 1, l = 1; i <= n; i++){
		cin >> x[i];
		for(register int j = l; j <= i; j++){
			if(x[i] - x[j] > D){l++;continue;}
			e[i].push_back(j);
			e[j].push_back(i);
		}
	}
	ll ans = 0;
	for(register int i = 1; i <= n; i++){
		memset(d, 0x3f, sizeof(d));
		d[i] = 0;
		cnt[i] = 1;	
		priority_queue<node, vector<node>, cmp> q;
		q.push((node){i, 0});
		while(!q.empty()){
			node tmp = q.top(); q.pop();

			if(d[tmp.v] < tmp.w)continue;
			int u = tmp.v, w = tmp.w;
			// cout << u << ' ' << w << endl;
			for(auto v : e[u]){
				if(d[v] > w + 1){
					d[v] = w + 1;
					cnt[v] = cnt[u];
					q.push((node){v, d[v]});
					// cout << "UPD" << v << ' ' << d[v] << endl;
				}
				else if(d[v] == w + 1){
					cnt[v] += cnt[u];
					// cout << "VCNT" << v << ' ' << cnt[v] << ' ' << cnt[u] << endl;
				}
			}
		}
		for(register int j = 1; j <= n; j++){
			// cout << j << ' ' << cnt[j] << ' ' << d[j] << ' ' ;
			if(cnt[j] == 2){
				ans++;
				// cout << i << ' ' << j << ' ';
			}
			// cout << endl;
			cnt[j] = 0;
		}
		// cout << endl;
	}
	cout << ans / 2<< endl;
}
void solve2(){
	cin >> n >> D;
	for(int i = 1, l = 1; i <= n; i++){
		cin >> x[i];
		while(abs(x[i] - x[l]) > D){//[l, i - 1] is the right one 
			if(i - 2 >= l)d2[l][0] = x[i - 1] - x[i - 2];
			if(i - 3 >= l)d2[l][1] = x[i - 2] - x[i - 3] + d2[l][0];
			len[l] = i - l - 1;
			// e[i - 1].push_back(l);
			l++;
		}
		if(i == n){
			while(l <= n){//[l, i] is the only choice
				if(i - 1 >= l)d2[l][0] = x[i] - x[i - 1];
				if(i - 2 >= l)d2[l][1] = x[i - 1] - x[i - 2] + d2[l][0];
				len[l] = i - l;
				// e[i].push_back(l);
				l++;
			}
		}
	}
	// for(int i = 1; i <= n; i++){
		// cout << "[" << i << ", " << i + len[i] << ']' << endl;

	// }
	ll ans = 0;
	for(register int i = 1; i <= n; i++){
		register ll L = i, R = i, tmpl = L, tmpr = R;
		register ll l[3], r[3];
		// cout << L << ' ' << R << endl;
		while(R < n){
			l[2] = R;r[2] = R + len[R];
			tmpl = l[2];tmpr = r[2];
			if(R - 1 >= L){l[1] = R - 1;r[1] = R - 1 + len[R - 1];tmpl = min(r[1] + 1, n); ans += r[1] - l[2];}
			if(R - 2 >= L){l[0] = R - 2;r[0] = R - 2 + len[R - 2];ans -= r[0] - l[2];}
			
			L = tmpl, R = tmpr;
			// cout << L << ' ' << R << ' ' << ans << endl;
			L = tmpl;

		}
		// cout << ans << endl;
	}
	cout << ans << endl;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cout.tie(0);
	cin >> c >> t;
	if(c <= 10){
		while(t--)solve();
	}
	else {
		while(t--)solve2();
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
*/
