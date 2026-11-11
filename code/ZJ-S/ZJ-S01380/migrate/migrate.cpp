#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e6 + 10;
const int M = 5e3 + 10;

int cid,n,d;
int a[N],p[N],s[N],b[N],c[N];
int f[M][M],g[M][M];

void solve(){
	cin >> n >> d;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	bool ff = 1;
	for (int i = 1 ; i <= n - 2 ; i++) ff &= (a[i + 1] - a[i] == a[i + 2] - a[i + 1]);
	if (ff){
		int D = a[2] - a[1],k = d / D;
		if (k <= 1) return cout << "0\n",void();
		k <<= 1;
		cout << max(0ll,n - k + 1) << endl;	
		return;
	}
	for (int i = 1,j = 1 ; i <= n ; i++){
		while (j < n && a[j + 1] - a[i] <= d) j++;
		s[i] = j;
	}
	for (int i = n,j = n ; i >= 1 ; i--){
		while (j > 1 && a[i] - a[j - 1] <= d) j--;
		p[i] = j;
	}
	//for (int i = 1 ; i <= n ; i++) cout << p[i] << ' ';
	//cout << endl;
	//for (int i = 1 ; i <= n ; i++) cout << s[i] << ' ';
	//cout << endl;
	int ans = 0;
	int L = 1,R = 1;
	while (L <= n){
		R = L;
		while (R < n && a[R + 1] - a[R] <= d) R++;
		//cout << "seg = " << L << ' ' << R << endl;
		for (int i = L ; i <= R ; i++){
			int now = i;
			f[i][i] = now;
			while(1){
				if (s[now] < R){
					for (int j = now + 1 ; j <= s[now] ; j++) f[i][j] = f[i][now] + j;
					now = s[now];
				}else{
					for (int j = now + 1 ; j <= R ; j++) f[i][j] = f[i][now] + j;
					break;
				}
			}
		}
		for (int i = L ; i <= R ; i++){
			int now = i;
			g[i][i] = now;
			while(1){
				if (p[now] > L){
					for (int j = now - 1 ; j >= p[now] ; j--) g[i][j] = g[i][now] + j;
					now = p[now];
				}else{
					for (int j = now - 1 ; j >= L ; j--) g[i][j] = g[i][now] + j;
					break;
				}
			}
		}
		for (int i = L ; i <= R ; i++)
			for (int j = i + 1 ; j <= R ; j++)
				ans += (abs(f[i][j] - g[j][i]) == 1);
		L = R + 1;
	}
	cout << ans << endl;
}
signed main(){
	//freopen("migrate3.in","r",stdin);
	//freopen("my.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; cin >> cid >> T;
	while (T--) solve();
	return 0;
}