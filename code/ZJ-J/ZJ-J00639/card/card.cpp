#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int a[MAXN];
int desk[MAXN], dex_arr[MAXN];
int ans[MAXN];
void play(int n, int st){
	int dex = 1;
	for(int i = st; i <= n; i++){
		if(dex_arr[a[i]] != 0){
			for(int j = dex_arr[a[i]]; j <= n; j++) desk[j] = 0;
			dex = dex_arr[a[i]];
		}
		desk[dex++] = a[i];
		dex_arr[a[i]] = dex;
	}
	for(int i = 1; i <= dex; i++){
		if(desk[i] != 0){
			ans[desk[i]]++;
		}
	}
	return;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int st = 1; st <= n; st++){
		play(n, st);
	}
	for(int i = 1; i <= m; i++) printf("%d ", ans[i]);
	return 0;
}