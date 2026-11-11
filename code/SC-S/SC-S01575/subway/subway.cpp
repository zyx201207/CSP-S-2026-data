#include <bits/stdc++.h>
// #define int long long
using namespace std;

int Never_gonna_give_you_up;
int target, length, source, query;
int values[1 << 15];
int lengths[1 << 15];

struct Node {
	signed target, weight;
} targets[501][1 << 15];

vector<pair<int, int> > sources[1 << 15];

int distances[1 << 15];
int currents[1 << 15];
static void dijkstra(int left, int right) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > weights;
	memset(distances, 0x1f, sizeof distances);
	memset(currents, 0, sizeof currents);
	weights.emplace(left, 0);
	distances[left] = 0;
	while (weights.size()) {
		auto current = weights.top(); weights.pop();
		if (currents[current.first]) continue;
		for (auto right : sources[current.first]) {
			if (distances[right.first] > distances[current.first] + right.second) {
				distances[right.first] = distances[current.first] + right.second;
				weights.emplace(right.first, distances[right.first]);
				currents[current.first] = 1;
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
//	cin.exceptions(ios::badbit | ios::failbit);
	
	cin >> Never_gonna_give_you_up;
	cin >> target >> length >> source >> query;
	for (int current = 1; current <= length; current++) cin >> values[current];
	for (int current = 1; current <= target; current++) {
		cin >> lengths[current];
		for (int right = 1; right <= lengths[current]; right++) 
			cin >> targets[current][right].target >> targets[current][right].weight;
		for (int left = 1; left <= lengths[current]; left++) 
			for (int right = 1; right <= lengths[current]; right++) {
				if (left == right) continue;
				sources[targets[current][left].target].emplace_back(targets[current][right].target, targets[current][left].weight + targets[current][right].weight);
			}
	}
	
//	for (int current = 1; current <= length; current++) {
//		cerr << current << ' ';
//		for (auto value : sources[current]) cerr << value.first << ' ' << value.second << ' ';
//		cerr << '\n';
//	}
	
	while (query--) {
		int left, right;
		cin >> left >> right;
		dijkstra(left, right);
		cout << distances[right] + values[left] + values[right] << '\n';
	}
	
	return 0;
}