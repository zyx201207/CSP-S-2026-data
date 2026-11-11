#include<bits/stdc++.h>
using namespace std;
int a[200025];
map <int , pair<int , int>> mp;
deque<int> v[300005];
deque<int> v2[300005];
int c[200025];
int main () {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		v[a[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		while (!v[i].empty() && v[i].size() > 1) {
			int a = v[i].front();
			v[i].pop_front();
			int b = v[i].front();
			c[a] += 1;
			c[b] -= 1;
			v2[i].push_back(a);
		}
		v2[i].push_back(v[i].front());
	}
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + c[i];
	}
	for (int i = 1; i <= m; i++) {
		int ans = 0;
		int last;
		while (!v2[i].empty()) {
			last = v2[i].front();
			v2[i].pop_front();
			ans = max(0 , last - c[last]);
		}
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}
