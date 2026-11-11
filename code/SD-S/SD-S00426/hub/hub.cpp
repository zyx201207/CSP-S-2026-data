#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 2e5 + 5;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ll c = read(), T = read();
	srand(time(0));
	while(T--){
		std::cout << rand() % 2 + 1 << '\n';
	}
	return 0;
}

