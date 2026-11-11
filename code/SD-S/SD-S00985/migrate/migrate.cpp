#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long a[2000010];
long long f[5010][5010];
long long g[5010][5010];

void sl(){
	long long n, d;
	cin >> n >> d;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(long long i = 0; i <= n; i++){
		for(long long j = 0; j <= n; j++){
			f[i][j] = INF;
			g[i][j] = 0;
		}
		g[i][i] = 1;
	}
	long long c = 0;
	for(long long i = 1; i <= n; i++){
		for(long long j = i + 1; j <= n; j++){
			for(long long k = i; k < j; k++){
				if(a[j] - a[k] > d || a[k] - a[i] > d) continue;
				f[i][j] = min(f[i][j], f[i][k] + 1);
			}
			for(long long k = i; k < j; k++){
				if(a[j] - a[k] > d || a[k] - a[i] > d) continue;
				if(f[i][k] + 1 == f[i][j]) g[i][j] += g[i][k];
			}
			if(g[i][j] == 2) c++;
		}
	}
	cout << c << endl;
	return;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long bh, sj;
	cin >> bh >> sj;
	while(sj--){
		sl();
	}




	return 0;
}
