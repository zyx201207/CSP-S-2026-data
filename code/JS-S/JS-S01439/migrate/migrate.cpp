#include <bits/stdc++.h>
#define go(i,l,r) for(int i = l; i <= r; i++)
#define re(i,r,l) for(int i = r; i >= l; i--)
using namespace std;
using ll = long long;

const int N = 2e6+5;
int c, t, n;
ll D, x[N];

ll dis(int a, int b) {return abs(x[a] - x[b]);}

const int M = 5005;
int f[N], d[M][M];

void t1_t6(){
	go(i,1,n) go(j,1,n) d[i][j] = 1e9+1;
	int ans = 0;
	go(i,1,n){
		f[i] = i, d[i][i] = 0;
		if(dis(i,i+1) <= D) d[i][i+1] = 1, f[i+1] = i;
		else continue;
		go(j,i+2,n){
			if(dis(j-1,j) > D) break;
			f[j] = f[j-1], d[i][j] = d[i][j-1];
			if(dis(f[j-1],j) > D) f[j] = j-1, d[i][j] ++;
		}
	}
	go(i,1,n) {go(j,1,n) printf("%3d", d[i][j] > 1e9? -1 : d[i][j]); //cout <<'\n';}
	go(v,1,n){
		re(u,v-1,1){
			if(d[u][v] > 1e9) break;
			int cnt = 0;
			//cout << u <<" - "<< v <<": ";
			go(p,u+1,v-1)
				if(d[u][p] + d[p][v] == d[u][v] && d[u][p+1] + d[p+1][v] == d[u][v]) cnt ++;//, cout << p <<' ';
			if(cnt == 2) ans ++;
			//cout <<'\n';
		}
	}
	cout << ans <<'\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	//cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> D;
		go(i,1,n) cin >> x[i];
		if(n <= 5000) {t1_t6(); continue;}
	}
	return 0;
}
