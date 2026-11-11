#include<bits/stdc++.h>
#define ll long long
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

int c, t;
ll n;
ll d;
ll x[2000005];
ll Sum;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::cin >> c >> t;
	while(t --> 0) {
		std::cin >> n >> d;
		for(int i = 1; i <= n; i ++) std::cin >> x[i];
		if(c == 0 || c == 11 || c == 12) {
			ll len = d / (x[2] - x[1]);
			if(len == 0 || len == 1 || n < (len << 1)) {
				std::cout << 0 <<'\n';
				continue;
			}
			std::cout << n - (len << 1) + 1 <<'\n';
		}
	}
}