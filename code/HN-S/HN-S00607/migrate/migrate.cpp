#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e5 + 5;
const int inf = 1e18 + 1e12;
int n;
ull d;
ll x[N],ans;
vector <int> ele;
void work (int u, int v){
	int cur = u;
	ele.clear();
	ele.push_back (u);
	while (cur != v){
		if (d >= x[v] - x[cur]){
			ele.push_back (v);
			break;
		}
		if (x[cur + 1] - x[cur] > d) return ;
		int nxt = upper_bound (x + 1, x + 1 + n, x[cur] + d) - x - 1;
		if (nxt >= v){
			ele.push_back (v);
			break;
		}
		ele.push_back (nxt);
		cur = nxt;
	}
	int flag = 0;
	for (int i = 2; i < ele.size(); i++){
		int pos2 = ele[i], pos1 = ele[i - 1];
		int lst1 = pos1 - 1, lst2 = pos1 - 2;
		if (lst1 <= ele[i - 2]) continue;
		if (lst2 <= ele[i - 2]){
			if (x[pos2] - x[lst1] <= d) flag++;
		}
		if (x[pos2] - x[lst1] <= d && x[pos2] - x[lst2] > d) flag++;
		if (flag > 1){
			return ;
		}
	}
	ans += flag;
}
void solve(){
	cin >> n >> d;
	ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 3; j <= n; j++){
			work (i, j);
		}
	}
	cout << ans << '\n';
} 
int main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C0,T;
	cin >> C0 >> T;
	while (T--) solve(); 
	return 0;
}
