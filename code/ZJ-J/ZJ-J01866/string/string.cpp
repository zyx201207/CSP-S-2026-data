// Pass 100
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	ll l, r;
	char op;
};

vector<Node> g;
int n;
ll ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	//
	cin >> n;
	ll l = 1, r;
	for (int i = 1; i <= n; i++){
		int a; char c;
		cin >> a >> c;
		r = l + a - 1;
		Node p; p.l = l; p.r = r; p.op = c;
		g.push_back(p);
		l = r + 1;
	}
	
	//
	l = 1;
	ll L = r;
	int bl = 0, br = n - 1;
	while (l <= r && br >= 0 && bl >= 0){
		int x = r - g[br].l + 1, y = g[bl].r - l + 1;
		if (g[bl].op != g[br].op) ans += min(x, y);
		if (x <= y){
			br--; r = g[br].r; l = L + 1 - r;
		}
		else{
			bl++; l = g[bl].l; r = L + 1 - l;
		}
	}
	
	//
	cout << ans << '\n';
	
	return 0;
}