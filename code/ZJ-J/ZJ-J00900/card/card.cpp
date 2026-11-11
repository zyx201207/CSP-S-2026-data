#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;

int n, m;
int a[N];
int pos[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i = 1; i <= n ; i++) {
		cin>>a[i];
	}
	
	memset(pos, 0, sizeof pos);
	
	for(int i = n; i >= 1; i--) {
		if(pos[a[i]] == 0) {
			pos[a[i]] = i;
		}
	}
		
	for(int i = 1; i <= n; i++) {
		int id = i;
		while(id <= n) {
			id = pos[a[id]];
			ans[a[id]]++;
			id++;
		}
	}
		
	for(int i = 1; i <= m; i++) {
		cout<<ans[i]<<" ";
	}

	return 0;
}