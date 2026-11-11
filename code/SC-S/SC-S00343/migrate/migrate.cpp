#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, T, n, d, p[N], Ans, g[N];
void Solve1(int L, int R){
	for(int i = L; i <= R; i++){
		g[i] = 1;
		int lst = i;
		for(int k = i + 1; k <= R; k++){
			g[k] = 0;
			if(p[k] - p[lst] > d)lst = k - 1;
			for(int w = lst; w >= max(i, lst - 2); w--)
				if(p[k] - p[w] <= d)g[k] += g[w]; 
			if(g[k] == 2)Ans++;
		}
	}
	return void();
}
void Solve2(int D){
	g[1] = 1;
	int lst = 1;
	for(int i = 2; i <= n; i++){
		g[i] = 0;
		if(D * (i - lst) > d)lst = i - 1;
		for(int w = lst; w >= max(1ll, lst - 2); w--)
			if(D * (i - w) <= d)g[i] += g[w];
	}
	for(int i = 1; i <= n; i++)if(g[i] == 2)Ans += n - i + 1;
	return void();
}
void Solve3(int pos){
	int l = 1, kl = 0, kr = 0;
	for(int i = pos + 1; i <= n; i++){
		while(p[i] - p[l] > d)l++;
		if(i - l < 2)continue;
		while(p[l + 1] - p[kl] > d)kl++;
		kr = kl;
		while(p[l + 2] - p[kr] > d)kr++;
		if(kl)Ans += kr - kl;
	}
	return void();
}
signed main(){
	freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--){
		Ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> p[i];
		if(c == 11 || c == 12){
			if(p[2] - p[1] > d)puts("0");
			else Solve2(p[2] - p[1]);
		}
		else if(c == 13 || c == 14){
			for(int i = 1; i <= n; i++)
				if(p[i] - p[1] <= d && p[n] - p[i] <= d){Solve3(i); break;}
		}
		else{
			int l = 1;
			for(int i = 2; i <= n; i++){
				if(p[i] - p[i - 1] <= d)continue;
				Solve1(l, i - 1);
				l = i;
			}
			Solve1(l, n);
		}
		cout << Ans << endl;
	}
	return 0;
}