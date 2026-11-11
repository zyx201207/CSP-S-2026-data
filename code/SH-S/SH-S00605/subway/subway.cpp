#include <bits/stdc++.h>
#define uint unsigned int
using namespace std;

struct Plan {
	int s, e;
};

int c, n, m, d, q;
vector<uint> et;
unordered_map<int, unordered_map<int, uint> > adj; // [spot][spot] = time
vector<Plan> P;
// station: 1 -> n
// line: -1 -> -m

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		uint tmp;
		cin >> tmp;
		et.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		uint k;
		cin >> k;
		for (uint s = 1; s <= k; s++) {
			uint a, b;
			cin >> a >> b;
			adj[0 - i - 1][a] = b;
			adj[a][0 - i - 1] = b;
			// cout << "#" << 0 - s << "-->" << a << ": " << b << "\n";
		}
	}
	for (int i = 0; i < q; i++) {
		Plan tmp;
		cin >> tmp.s >> tmp.e;
		P.push_back(tmp);
	}

	for (int i = 0; i < q; i++) {
		uint ans = 0;
		uint start = P[i].s;
		uint end = P[i].e;
		
		ans += et[start - 1] + et[end - 1];
		// bfs here
		// unordered_set<int> vis;
		unordered_map<int, uint> step;
		stack<int> tasks;
		step[start] = 0;
		tasks.push(start);
		while (!tasks.empty()) {
			int task = tasks.top();
			tasks.pop();
			// cout << task << ": " << step[task] << "\n";
			if (task == end) continue;
			for (const auto &j: adj[task]) {
				// cout << "!!!!!" << task << "-->" << j.first << ": " << adj[-1][2] << "\n";
				if (j.first == start) continue;
				// cout << "!!!!!" << "___" << j.first << "\n";
				if (step.find(j.first) == step.end()) {
					// cout << "!!!!!" << "___" << j.first << "\n";
					// cout << "--" << j.first << ": " << step[task] + j.second << "\n";
					tasks.push(j.first);
					step[j.first] = step[task] + j.second;
				} else {
					if (step[j.first] > step[task] + j.second) {
						tasks.push(j.first);
						step[j.first] = step[task] + j.second;
					} 
				} 
			}
		}

		ans += step[end];
		cout << ans << "\n";
	}
	return 0;
}
