#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1, s2, c1, c2;
struct DSU
{
	const int n;
	vector<int> fa, sz;
	DSU(int _n) : n(_n), fa(n + 1), sz(n + 1) {
		for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	}
	int find(int x) {
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return;
		if(sz[x] > sz[y]) swap(x, y);
		fa[x] = y;
		sz[y] += sz[x];s
	}
	bool same(int x, int y) { return find(x) == find(y); }
};
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	DSU d(128);
	d.merge('A', 'B');
	d.merge('B', 'C');
	d.merge('D', 'F');
	if(c1 == c2){
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			if(d.same(s1[2], s2[2])){
				if(s1[2] > s2[2]) swap(s1[2], s2[2]);
				if(s1[2] == 'A' && s2[2] == 'B') cout << "1111";
				else if(s1[2] == 'B' && s2[2] == 'C') cout << "1111"; 
				else if(s1[2] == 'D' && s2[2] == 'F') cout << "1111";
				else cout << "1110"; 
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
