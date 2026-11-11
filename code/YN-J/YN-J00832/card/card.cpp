#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n, m, tmp;
vector<int> vec;
vector<int> vec_t;
int js[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			tmp = -1;
			for (int k = 0; k < vec_t.size(); k++) {
				if (vec[j] == vec_t[k])
					tmp = k;
			}
			if (tmp == -1) {
				vec_t.push_back(vec[j]);
			} else {
				vec_t.erase(vec_t.begin() + tmp, vec_t.end());
				vec_t.push_back(vec[j]);
			}
		}
		for (int j = 0; j < vec_t.size(); j++) {
			js[vec_t[j]]++;
		}
		vec_t.clear();
	}
	for (int i = 1; i <= m; i++) {
		cout << js[i] << " ";
	}
	return 0;
}