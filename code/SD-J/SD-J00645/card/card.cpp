#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5; 
int a[N], card[N];
vector<int> g;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	bool spA = true;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(i > 1 && a[i] < a[i - 1]) spA = false;
	}
	if(spA) {
		for(int i = 1;i <= m;i++) cout << i << " ";
	}
	else {
		for(int k = 1;k <= n;k++) {
			g.clear();
			for(int i = k;i <= n;i++) {
				if(!g.empty()) {
					int l = g.size();
					int pos, flag = false;
					for(int j = 0;j < (int)g.size();j++) {
						if(g[j] == a[i]) {
							flag = true;
							pos = j;
							break;
						}
					}
					if(flag) {
						for(int j = pos;j < (int)g.size();j++) g[j] = 0;
					}
					g.push_back(a[i]);
				}
				else g.push_back(a[i]);
			}
			for(int i = 0;i < (int)g.size();i++) card[g[i]]++;
		}
		for(int i = 1;i <= m;i++) cout << card[i] << " ";
	}
	return 0;
}
