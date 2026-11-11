#include <iostream>
using namespace std;
int c,t;
int n,d;
int x[1000];
int same_num[505][505];
int same_length[505][505];
int f[1001][1001];
const int inf = 0x3f3f3f3f;
void solve() {
	cin >> n >> d;
	for(int i=1;i<=n;++i) cin >> x[i];
	for(int i=1;i<=n;++i) {
		same_num[i][i] = 0;
		for(int j=i+1;j<=n;++j) {
			same_num[i][j] = same_num[j][i] = 1;
			f[j][i] = f[i][j] = (x[j] - x[i] > d ? inf : x[j] - x[i]);
		}
	}
	for(int k=1;k<=n;++k) {
		for(int i=1;i<k;++i) {
			for(int j=i+1;j<=n;++j) {
				if(f[i][j] == inf || f[i][k] == inf || f[k][j] == inf) continue;
				if(f[i][j] < f[i][k] + f[k][j]) continue;
				if(f[i][j] > f[i][k] + f[k][j]) {
					same_num[i][j] = same_num[i][k] * same_num[k][j];
					same_length[i][j] = f[i][k] + f[k][j];
				}
				if(f[i][j] == f[i][k] + f[j][k]) {
					same_num[i][j] += same_num[i][k] * same_num[k][j];
				}
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			ans += (same_num[i][j] == 2);
//			cout << same_num[i][j] << " \n"[j==n];
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();
}
