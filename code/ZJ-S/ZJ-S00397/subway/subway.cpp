#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 500+10;
const int M = 5e5+10;
const int D = 20+10;

int c,n,m,d,p;
int w[M];
int t[D][N];

struct Nd{
	int v,w,id;
};
vector<Nd> ve[N];
vector<Nd> g[N];

int ans[2010][2010];

void Floyd(){
	for (int k = 1 ; k <= m ; k++){
		for (int i = 1 ; i <= m ; i++){
			for (int j = 1 ; j <= m ; j++){
				if (ans[i][j] > ans[i][k]+ans[k][j]){
					ans[i][j] = ans[i][k]+ans[k][j];
				}
			}
		}
	}
}
int a[D];
int s[D];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1 ; i <= m ; i++){
		for (int j = 1 ; j <= m ; j++){
			ans[i][j] = 1e18;
		}
		ans[i][i] = 0;
	}
	for (int i = 1 ; i <= m ; i++){
		cin >> w[i];
	}
	for (int i = 1 ; i <= n ; i++){
		int k;
		cin >> k;
		for (int i = 1 ; i <= k ; i++){
			cin >> a[i] >> s[i];
		}
		for (int i = 1 ; i <= k ; i++){
			for (int j = i+1 ; j <= k ; j++){
				int x = a[i],y = a[j];
				ans[x][y] = s[i]+s[j];
				ans[y][x] = s[i]+s[j];
			}
		}
	}
	Floyd();
	while (p--){
		int x,y;
		cin >> x >> y;
		cout << ans[x][y]+w[x]+w[y] << endl;
	}
	return 0;
}
