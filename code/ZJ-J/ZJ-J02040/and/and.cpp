#include <bits/stdc++.h>
using namespace std;
struct Node {
	int num;
	bitset<32> sw;
};
vector<Node> v;
vector<int> tj[32];
void f(int i) {
	int x = 0;
	int t = v[i].num;
	while (t > 0) {
		v[i].sw[x ++] = t & 1;
		if (v[i].sw[x - 1] == true) {
			tj[x - 1].push_back(v[i].num);
		}
		t >>= 1;
	}
	return;
}

bool cmp(Node A, Node B) {
	return A.num > B.num;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n ; i ++) {
		int t;
		cin >> t;
		v.push_back({t});
		
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i ++) {
		f(i);
	}
	if (m == 1) {
		cout << v[0].num;
	}
	vector<int> md;
	for (int i = 0; i < n; i ++) {
		md.push_back(v[i].num);
	}
	for (int i = 31; i >= 0 ; i --) {
		if (tj[i].size() > m) {
			vector <int> kxx;
			int ans = 0;
			for (int j = 0; j < md.size(); j ++) {
				int left = 0;
				int right = tj[i].size() - 1;
				while (left < right) {
					int row = (left + right) / 2;
					if (md[j] == tj[i][row]){
						ans ++;
						kxx.push_back(md[j]);
						break;
					}
					if (tj[i][row] > md[j]) {
						right = row - 1;
					} else {
						left = row + 1;
					}
				}
			}
			if (ans > m) {
				md = kxx;
			}
		}
	}
	long long ans = md[0];
	for (int i = 1 ; i < m; i ++) {
		ans &= md[i];
	}
	cout << ans;
	return 0;                    
}