#include <bits/stdc++.h>

using namespace std;

long long c, n, m, d, q;
long long w[500005];
int a[503][500005];
int t[503][500005];
int k[503];

using ull = unsigned long long;

vector<int> lines[500005];
// time, (line, stat, begin)
using Node = pair<ull, tuple<int, int, int>>;

long long calchash(int a, int b) {
    return ((long long)a) << 32 | b;
}

vector<long long> solvemulti(int b, vector<int> e) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
        unordered_map<long long, ull> dis;

	for (auto k : lines[b]) {
            pq.push({0, {k, b, k}});
	}

        unordered_map<int, vector<Node>> n;
        
        // index -> actual
        unordered_map<int, int> endpoints;
        for (int i = 0; i < e.size(); ++i) {
            endpoints[e[i]] = i;
        }
        
        while (!pq.empty()) {
	    auto elem = pq.top();
	    pq.pop();

	    auto line = get<0>(elem.second);
	    auto station = get<1>(elem.second);

	    auto hsh = calchash(line, station);
            if (dis.count(hsh) == 0) {
	        dis[hsh] = elem.first;
	    }
	    else {
	        if (elem.first < dis[hsh]) {
		    dis[hsh] = elem.first;
		}
		else {
		    continue;
		}
	    }

	    if (endpoints.count(station)) {
	        n[station].push_back(elem);
	    }

            for (auto l : lines[station]) {
		pq.push({elem.first + t[line][station] + t[l][station], {l, station, get<2>(elem.second)}});
	    }	   

	    for (int st = 1; st <= k[line]; ++st) {
	        pq.push({elem.first, {line, a[line][st], get<2>(elem.second)}});
	    } 
	}
	
	vector<long long> result;
	result.resize(e.size());
	
	for (auto endp : endpoints) {
	    ull cstt = 0x7fffffffffffffff;
	    for (auto kk : n[endp.first]) {
	        auto cst = kk.first + w[b] + w[endp.first] + t[get<2>(kk.second)][b] + t[get<0>(kk.second)][endp.first];
	        cstt = min(cst, cstt);
	    }
	    result[endp.second] = cstt;
	}
	return result;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> n >> m >> d >> q;

    for (int _ = 1; _ <= m; ++_) {
        cin >> w[_];
    }

    for (int _ = 1; _ <= n; ++_) {
        cin >> k[_];

	for (int l = 1; l <= k[_]; ++l) {
	    cin >> a[_][l];
	    cin >> t[_][a[_][l]];
	    lines[a[_][l]].push_back(_);
	}
    }

    vector<long long> result;
    result.resize(q);
    // begin -> list of(end, index)
    unordered_map<int, pair<vector<int>, vector<int>>> kk;
    for (int _ = 0; _ < q; ++_) {
        int b, e;
	cin >> b >> e;
	
	kk[b].first.push_back(e);
	kk[b].second.push_back(_);
    }
    
    for (const auto &q : kk) {
        auto res = solvemulti(q.first, q.second.first);
        
        for (int i = 0; i < res.size(); ++i) {
            result[q.second.second[i]] = res[i];
        }
    }
    
    for (auto ff : result) {
        cout << ff << endl;
    }
}
