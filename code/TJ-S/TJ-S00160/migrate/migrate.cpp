#include <bits/stdc++.h>
using namespace std;

namespace z {

#define int long long
const int N = 2e6 + 5;
int a[N], pre[N], nxt[N], f[N], g[N];  
void solve() {
	int n, d; cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < N; i++) pre[i] = nxt[i] = f[i] = g[i] = 0;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j + 1 <= n && a[j + 1] - a[i] <= d) j++;
		nxt[i] = j;
	}
	for(int i = n, j = n; i >= 1; i--) {
		while(j - 1 >= 1 && a[i] - a[j - 1] <= d) j--;
		pre[i] = j;
	}
	for(int i = n; i >= 1; i--) {
		f[i] = 1;
		if(i == pre[nxt[i]]) f[i] += f[nxt[i]];
		for(int j = i + 1; j <= nxt[i] - 1; j++)
			f[i] += pre[j] == i;
	}
	for(int i = 1; i <= n; i++) {
		g[i] = 1;
		if(i == nxt[pre[i]]) g[i] += g[pre[i]];
		for(int j = i - 1; j >= pre[i] + 1; j--)
			g[i] += nxt[j] == i;
	} 
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int j = nxt[nxt[i]];
		if(nxt[nxt[i]] == nxt[i]) continue;
		if(pre[j] != nxt[i] - 1) continue;
		if(pre[pre[j]] == i) {
			ans += f[j] * g[i];
		}
		if(pre[pre[j]] < i) {
			ans += f[j];
		}
	}
	for(int i = 1; i <= n; i++) {
		if(pre[i] == pre[pre[i]]) continue;
		int j = pre[pre[i]];
		if(pre[i] != nxt[j] - 1) continue;
		if(nxt[nxt[j]] > i) {
			ans += g[j];	
		}
	}
	for(int i = 1; i <= n; i++) {
		int x = nxt[i];
		if(pre[x - 1] < i) {
			for(int j = max(i+2,x); j < nxt[x]; j++) {
				ans += pre[j] == x - 1;
			}
		} 
		
	}
	cout <<ans << '\n';
}
void main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int C, T; cin >> C >> T;
	while(T--) solve();
	
}

#undef int 

}

int main() {
	z::main();
	return 0;
}

/*

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
9 5
2 3 6 8 12 13 15 16 17 


0 1
12 3
0 2 3 4 7 9 10 11 12 13 18 19 

0 1
14 8
6 8 9 12 16 18 23 24 27 28 30 37 45 49 

0 1
7 3
0 1 2 3 5 6 9 

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/

