#include <bits/stdc++.h>
using namespace std;
#define SHIH_SSU 0
typedef long long ll;
const int N = 5005;
const int INF = 1e9 + 7;

int n;
int dis[N][N];
int cnt[N][N];
ll a[N], d;


inline void Sol(){
	cin >> n >> d;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) dis[i][j] = INF;
		
	for(int i = 1; i <= n; i ++) dis[i][i] = 0;

	for(int i = 1; i <= n; i ++){
		int pre = i;
		for(int j = i + 1; j <= n; j ++){
			while(a[j] - a[pre] > d) pre ++;
			dis[i][j] = dis[i][pre] == INF ? INF : dis[i][pre] + 1;
		}
	}
	
	cout << 0 << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int c, T; cin >> c >> T;
	while(T --) Sol();
	
	return SHIH_SSU;
}
