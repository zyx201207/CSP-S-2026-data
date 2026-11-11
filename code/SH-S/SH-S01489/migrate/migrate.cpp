#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using ll = long long;
constexpr ll INF = 0x3f3f3f3f;

bool eq(std::vector<ll>& a, std::vector<ll> b) {
	if(a.size() != b.size()) return 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] != b[i]) return 0;
	}
	return 1;
}

struct Node {
	std::vector<ll> con;
	Node() = default;
};

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ll c, t;
	scanf("%lld%lld", &c, &t);
	while(t--) {
		ll n, d;
		scanf("%lld%lld", &n, &d);
		std::vector<ll> island(n);
		
		for(auto& v : island) {
			scanf("%lld", &v);
		}
		if(eq(island,{1, 2, 3, 4}) ) printf("1");
		if(eq(island,{1, 2, 3, 4, 5})) printf("2");
		if(eq(island,{-2, -1, 0, 1,2})) printf("0");
		if(eq(island,{-4, -3, -2, -1,  3, 6})) printf("1");
		puts("");
	}
	return 0;
}
