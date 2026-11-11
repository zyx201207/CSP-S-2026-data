#include <bits/stdc++.h>
using namespace std;

const int M = 3e5 + 10;
const int N = 5e5 + 10;
int n, m, a[N], ans[M];
bool vis[M];
vector<int> t;

int main () {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (vis[a[j]] == false) {
				vis[a[j]] = true;
				t.push_back(a[j]);
			} else {
				while (t[t.size() - 1] != a[j]) {
					vis[t[t.size() - 1]] = false;
					t.pop_back();	
				}
//				for (int j = 0; j < t.size(); j++)
//					cout << t[j] << " ";		
//				cout << "\n";		
			}
		}
		for (int j = 0; j < t.size(); j++)
			ans[t[j]]++, vis[t[j]] = false;
		t.clear();
	}
	for (int i = 1; i <= m - 1; i++)
		cout << ans[i] << " ";
	cout << ans[m]; 
	return 0;
}
