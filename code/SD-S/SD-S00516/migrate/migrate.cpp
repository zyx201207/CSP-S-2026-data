#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e2 + 10;
const int INF = 0x3F3F3F3F;

int adj[N][N];
void Solve(){
	ll n,d;cin >> n >> d;
	vector<ll> x(n + 1,0);
	for(int i = 1;i <= n;i++){
		cin >> x[i];
	}
	vector<vector<ll> > f(n + 1,vector<ll>(n + 1,INF)),cnt(n + 1,vector<ll>(n + 1,0));
	for(int i = 1;i <= n;i++){
		int j = i;
		while(j <= n && x[j] - x[i] <= d){
			f[i][j] = 1;
			cnt[i][j] = 1;
			j ++;
		}
	}
	
	for(int i = 1;i <= n;i++){
		f[i][i] = 0;
	}
	
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(f[i][j] > f[i][k] + f[k][j]){
					f[i][j] = f[i][k] + f[k][j];
					cnt[i][j] = 1;
				}
				else if(f[i][j] == f[i][k] + f[k][j] && f[i][j] != INF){
					cnt[i][j] ++;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j++){
			//cout << cnt[i][j] << " ";
			if(cnt[i][j] == 2){
				ans ++;
			}
		}
		//cout << "\n";
	}
	cout << ans << "\n";
	
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int c,T;cin >> c >> T;
	while(T--) Solve();
	return 0;
}

