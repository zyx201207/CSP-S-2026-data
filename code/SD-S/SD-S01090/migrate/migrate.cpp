#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define MSOD

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e6 + 5, N1 = 5e3 + 5;
const ull P = 212370440130137957;

int testid;

int n;
ll d;
ll x[N];


int hd, tl;
int q[N1], f[N1][N1];
ull h[N1], g[N1][N1]; 

void task1() {
	for(int i = 1 ; i <= n ; i ++) fill(f[i] + 1, f[i] + n + 1, 2e9);
	for(int i = 1 ; i <= n ; i ++) {
		fill(h, h + n + 1, 0);
		hd = 1, tl = 0;
		q[++ tl] = i, f[i][i] = 0, g[i][i] = h[0] = 1;
		for(int j = i + 1 ; j <= n ; j ++) {
			while(hd <= tl && x[j] - x[q[hd]] > d) {
				h[f[i][q[hd]]] += P - g[i][q[hd]], h[f[i][q[hd]]] %= P, hd ++;
			}
			if(hd > tl) break;
			f[i][j] = f[i][q[hd]] + 1, g[i][j] = h[f[i][q[hd]]], h[f[i][j]] += g[i][j], h[f[i][j]] %= P;
			q[++ tl] = j;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++) {
		for(int j = i ; j <= n ; j ++) {
			if(f[i][j] <= n && g[i][j] == 2) ans ++;
		}
	}
	cout<<ans<<endl;
	return;
}



void task2() {
	d = d / (x[2] - x[1]);
	if(d <= 1) {cout<<0<<endl;return;}
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++) {
		if(i + d * 2 - 1 > n) break;
		ans ++;
	}
	cout<<ans<<endl;
	return;
}

int cnt = 0;
void TEST() {
	cin>>n>>d;
	for(int i = 1 ; i <= n ; i ++) cin>>x[i];
	if(testid <= 10) task1();
	else if(testid <= 12) task2();
	return;
}



signed main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int TC = 1;
#ifdef MSOD
	cin>>testid>>TC;
#endif
	while(TC --) TEST();
	return 0;
}
