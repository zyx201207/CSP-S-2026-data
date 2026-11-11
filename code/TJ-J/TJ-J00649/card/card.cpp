#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N];
bool vis[N];
int res[N];

struct note {
	int p;
	int b;
};

vector<note> v;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			if (vis[j]) continue;
			int k = a[j];
			bool f = false;
			for (int z=0; z<v.size(); z++) {
				if (v[z].p == k) {
					// cout << "找到重复\n";
					f = true;
				}
				if (f) {
					// cout << "开始清楚\n";
					int idx = v[z].b;
					vis[idx] = true;
					v.pop_back();
				}
			}
			// if (f) cout << "有重复\n" << endl;
			// else cout << "无重复\n" << endl; 
			note st = {k, j};
			v.push_back(st);
			// for (int z=0; z<v.size(); z++) cout << v[z].b << " - ";
			// cout << endl;
			// cout << k << ' ';
		}
		note temp = v.back();
		res[temp.p]++;
		// cout << endl;
	}
	
	for (int i=1; i<=m; i++) {
		cout << res[i] << ' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
