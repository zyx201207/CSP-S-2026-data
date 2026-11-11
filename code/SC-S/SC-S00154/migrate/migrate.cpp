#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c,t,n;
ll d,a[N];
ll ans,minn_len = N + 1,hx[N];
ll minn(ll x,ll y){
	if (x > y) return y;
	else return x;
}
void dfs(int l,int r,int w){
	if (l == r){
		if (minn_len <= w){
			minn_len = w;
			hx[minn_len]++;
		}
		return;
	}
	for (int i = l + 1; i <= r; i++){
		if (a[i] - a[l] <= 0){
			dfs(i,r,w + 1);
		}
		else return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--){
		ans = 0;
		scanf("%d%d",&n,&d);
		for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
		for (int i = 1; i <= n - 2; i++){
			for (int j = i + 2; j <= n; j++){
				minn_len = N + 1;
				dfs(i,j,0);
				if (minn_len != N + 1 && hx[minn_len] == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}