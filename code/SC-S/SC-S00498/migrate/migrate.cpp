#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f3f;
int C, n, d, a[2000005], f[2000005], g[2000005], q[2000005], sum[2000005], bel[2000005], ber[2000005], tot[2000005], head, ans;
void SolveA(){
	f[1] = 1; g[1] = 0; int head = 0, tail = -1; q[++ tail] = 1; sum[0] = 1;
	for(int i = 2; i <= n; i ++){
		while(head <= tail && a[i] - a[q[head]] > d) sum[g[q[head]]] -= f[q[head]], head ++;
		if(head <= tail){
			f[i] = sum[g[q[head]]];
			g[i] = g[q[head]] + 1;
		}
		else break;
		ans += (f[i] == 2) * (n - i + 1); q[++ tail] = i; sum[g[i]] += f[i];
	}
	for(int i = 0; i <= n; i ++){
		sum[i] = 0;
	}
	cout << ans << "\n";
}
void SolveB(){
	bel[1] = 1;
	while(bel[1] != n && a[bel[1] + 1] - a[1] <= d) bel[1] ++;
	for(int i = 2; i <= n; i ++){
		bel[i] = max(i, bel[i - 1]);
		while(bel[i] != n && a[bel[i] + 1] - a[i] <= d) bel[i] ++;
	}
	ber[n] = n;
	while(ber[n] != 1 && a[n] - a[ber[n] - 1] <= d) ber[n] --;
	for(int i = n - 1; i >= 1; i --){
		ber[i] = min(ber[i + 1], i);
		while(ber[i] != 1 && a[i] - a[ber[i] - 1] <= d) ber[i] --;
	}
	for(int i = 2; i <= n; i ++){
		if(i - ber[i] >= 2) tot[ber[i]] ++;
	}
	for(int i = 1; i < n; i ++){
		if(i != bel[i]){
			ans += tot[bel[i] - 1];
		}
		if(i + 1 - ber[i + 1] >= 2) tot[ber[i + 1]] --;
	}
	cout << ans << "\n";
}
void Solve(int Case){
	cin >> n >> d; ans = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	int flag = 1, flag2 = 0;
	for(int i = 2; i <= n; i ++){
		if(a[i] - a[i - 1] != a[2] - a[1]){
			flag = 0;
		}
		if(a[i] - a[1] <= d && a[n] - a[i] <= d){
			flag2 = 1;
		}
	}
	if(n <= 5000){
		for(int i = 1; i <= n; i ++){
			f[i] = 1; g[i] = 0; int head = 0, tail = -1; q[++ tail] = i; sum[0] = 1;
			for(int j = i + 1; j <= n; j ++){
				while(head <= tail && a[j] - a[q[head]] > d) sum[g[q[head]]] -= f[q[head]], head ++;
				if(head <= tail){
					f[j] = sum[g[q[head]]];
					g[j] = g[q[head]] + 1;
				}
				else break;
				ans += (f[j] == 2); q[++ tail] = j; sum[g[j]] += f[j];
			}
			for(int j = 0; j <= n; j ++){
				sum[j] = 0;
			}
		}
		cout << ans << "\n";
		return;
	}
	if(flag){
		SolveA();
		return;
	}
	if(flag2){
		SolveB();
		return;
	}
	for(int i = 1; i <= n; i ++){
		f[i] = 1; g[i] = 0; int head = 0, tail = -1; q[++ tail] = i; sum[0] = 1;
		for(int j = i + 1; j <= n; j ++){
			while(head <= tail && a[j] - a[q[head]] > d) sum[g[q[head]]] -= f[q[head]], head ++;
			if(head <= tail){
				f[j] = sum[g[q[head]]];
				g[j] = g[q[head]] + 1;
			}
			else break;
			ans += (f[j] == 2); q[++ tail] = j; sum[g[j]] += f[j];
		}
		for(int j = 0; j <= n; j ++){
			sum[j] = 0;
		}
	}
	cout << ans << "\n";
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> C >> t;
	for(int i = 1; i <= t; i ++){
		Solve(i);
	}
	return 0;
}
/*
migrate < migrate1.in > migrate1.out
fc migrate1.out migrate1.ans
migrate < migrate2.in > migrate2.out
fc migrate2.out migrate2.ans
migrate < migrate3.in > migrate3.out
fc migrate3.out migrate3.ans
migrate < migrate4.in > migrate4.out
fc migrate4.out migrate4.ans

*/