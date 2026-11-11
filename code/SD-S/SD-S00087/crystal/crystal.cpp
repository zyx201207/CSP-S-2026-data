#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll NM = 1e8;
ll n;
ll m;
ll nb[500010];
ll chafen[500010];
ll tong[114514];
ll he;
ll dahe[256];
int ans = 1;
ll read() {
	char a;
	ll x = 0,f = 1;
	a = getchar();
	if(a == '-') f = -1;
	else x = (ll)(a-'0');
	a = getchar();
	while(a>='0'&&a<='9') {
		x *= 10;
		x += (ll)(a-'0');
		a = getchar();
	}
	return x*f;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; i++) {
		nb[i] = read();
	}
	if(n>5000&&m>NM) {
		ll k = nb[2]-nb[1];
		ll o = 0;
		for(ll i = 1; i*k+o<=m; i++) {
			ans++;
			o += i*k;
		}
	}else if(n>5000){
		for(int i = 1; i <= n; i++){
			tong[nb[i]+101]++;
		}
		int p = 0,q = 0,y = 0;
		if(tong[1]) q=1;
		dahe[1] = tong[1];
		for(int i = 2; i <= 201; i++){
			if(tong[i]){
				p = q;
				q = i;
				chafen[i] = q-p;
			}
			dahe[i] = dahe[i-1]+tong[i]; 
		}
		for(int i = 1; i <= 201; i++){
			he = 0;
			y = tong[i];
			for(int j = 1; j+i<=201; j++){
				he += (dahe[i+j-1]-dahe[i-1])*chafen[i+j];
				if(he <= m) y += tong[i+j];
			}
			ans = max(ans,y);
		}
	}else{
		sort(nb+1,nb+n+1);
		for(int i = 2; i <= n; i++){
			chafen[i] = nb[i]-nb[i-1];
		}
		for(int i = 1; i <= n; i++){
			he = 0;
			for(int j = 1; j+i<=n; j++){
				he += (ll)j*chafen[i+j];
				if(he <= m) ans = max(ans,j+1);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
/*
7 16
-15 -10 -5 0 5 10 15
*/
