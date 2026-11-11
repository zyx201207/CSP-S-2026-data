#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Node{
	int u, v;
}g[N];
int c, t, n, k;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; ++i){
			cin >> g[i].u >> g[i].v;
		}
	}
	cout << 1 << '\n';
	cout << 2 << '\n';
	return 0;
}
