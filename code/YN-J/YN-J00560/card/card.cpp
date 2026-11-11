#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec;

vector<int> tong;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin >> n >> m;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	for (int i = 0; i < vec.size(); i++) {
		vector<int> h(n, 0);
		for (int j = 0; j < n; j++) {
			h.push_back(vec[i]);
			if (h[i] == h[j]) {
				for (int k = 0; k < j; k++) {
					h.erase(h.begin());
				}
			}
		}
		tong[h[i]]++;
		vec.erase(vec.begin());
	}
	for (int i = 1; i <= m; ++i) {
		cout<<tong[i]<<" ";
	}



	return 0;
}