#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using ll = long long;
constexpr ll INF = 0x3f3f3f3f;

struct Node {
	std::vector<ll> Con;
	std::vector<ll> val;
	Node() = default;
};
void dij(std::vector<Node>& graph, int start, std::unordered_map<ll, ll>& dist) {
	struct cmp {
		ll id, dist;
		cmp(ll id, ll dist)
		: id(id), dist(dist) {}
		
		bool operator<(const cmp& v2) const {
			return dist > v2.dist;
		}
	};
	for(int i = 0; i < graph.size(); i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	std::vector<short> vst(graph.size());
	vst[start] = true;
	
	std::priority_queue<cmp> heap;
	heap.emplace(start, 0);
	while(!heap.empty()) {
		auto curr = heap.top();
		heap.pop();
		
		auto& nd = graph[curr.id];
		for(int i = 0; i < nd.Con.size(); i++) {
			dist[nd.Con[i]] = std::min(dist[nd.Con[i]], curr.dist + nd.val[i]);
			if(!vst[nd.Con[i]]) heap.emplace(nd.Con[i], dist[nd.Con[i]]);
			vst[nd.Con[i]] = true;
		}
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ll c, n, m, d, q;
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	std::vector<Node> graph(m * 2 + n);
	for(int i = 0; i < m; i++) {
		ll x;
		scanf("%lld", &x);
		graph[i].Con.push_back(i + m);
		graph[i + m].Con.push_back(i);
		graph[i].val.push_back(x);
		graph[i + m].val.push_back(x);
	}
	for(int i = 0; i < n; i++) {
		ll size;
		scanf("%lld", &size);
		for(int j = 0; j < size; j++) {
			ll a, t;
			scanf("%lld%lld", &a, &t);
			graph[a + m - 1].Con.push_back(i + m * 2);
			graph[i + m * 2].Con.push_back(a + m - 1);
			graph[a + m - 1].val.push_back(t);
			graph[i + m * 2].val.push_back(t);
		}
	}
	
	std::unordered_map<ll, std::unordered_map<ll, ll>> dists;
	for(int i = 0; i < m; i++) {
		dij(graph, i, dists[i]);
	}
	
	while(q--) {
		ll f, t;
		scanf("%lld%lld", &f, &t);
		printf("%lld\n", dists[f - 1][t - 1]);
	}
	return 0;
}
