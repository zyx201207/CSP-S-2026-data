#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5 , M = 3e5 + 5;
int n , m;
int idx[N];
int pos[M];
int ans[M];
int main() {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> a(n + 1);
	queue<int> re;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		idx[pos[a[i]]] = i;
		pos[a[i]] = i;
	}
	for(int i = 1;i <= n;i++) {
		if(idx[i] != 0) {
			re.push(i);
		}
	}
	int start;
	for(int i = 1;i <= n;i++) {
		while(!re.empty() && re.front() < i) {
			re.pop();
		}
		if(re.empty()) {
			start = i;
		}
		else {
			int r = re.front();
			re.pop();
			start = idx[r];
		}
		for(int j = start;j <= n;j++) {
			ans[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
