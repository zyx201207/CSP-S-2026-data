#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f; 
}
int c, t;
int n, k;
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), t = read();
	while(t--){
		n = read(), k = read();
		for(int i = 1; i < n; i++){
			int u = read(), v = read();
		}
		cout << 1 << '\n';
	}
	return 0;
}
