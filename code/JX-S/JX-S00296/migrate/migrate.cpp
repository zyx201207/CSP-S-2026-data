#include <iostream>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 7;
typedef long long ll;
typedef pair <int, int> pll;
int c, t;
int n;
ll d, x[N], s;
int to[N], f[N][2], k[N], h[N];
void solve(){
	cin >> n >> d; s = 0;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	int t = 0;
	for(int i = 1; i <= n; i++){
		while(t < n && x[i] + d >= x[t + 1]) t++;
		to[i] = t;
		//cout << to[i] << " ";
	}
	//cout << "\n";
	for(int i = n; i >= 1; i--){
		if(to[i] == to[i - 1]) f[i][0] = 0;
		else f[i][0] = f[to[i]][0] + max(0, to[i] - max(to[i - 1], i));
		//cout << f[i][0] << " ";
	}
	//cout << "\n";
	for(int i = n; i >= 1; i--){
		if(to[i] == i){ f[i][1] = 0; continue ; }
		int r = to[to[i]];// h[i] = h[to[i]];
		if(to[i] == i + 1){
			f[i][1] = f[i + 1][1];
		}else{
			k[i] = f[i][1] = max(min(to[to[i] - 1], to[to[i]] - 1) - to[to[i] - 2], 0);
			int l = to[to[i] - 1];
			if(l < r - 1) f[i][1] += f[to[i]][1];
			else if(l == r - 1) f[i][1] += f[to[i]][1] - k[to[i]] - h[to[i]];
			else if(to[to[i] - 2] != l) f[i][1] += f[to[to[i]]][0] + 1, h[i] += f[to[to[i]]][0] + 1;
		}
		s = s + f[i][1];
		//cout << f[i][1] << " " << i << "\n";
		//cout << to[i] << " " << v[i] << " " << f[i][0] << " " << k[i] << " " << f[i][1] << "\n";
	}
	for(int i = 1; i <= n; i++) f[i][0] = f[i][1] = h[i] = k[i] = to[i] = 0;
	cout << s << "\n";
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
