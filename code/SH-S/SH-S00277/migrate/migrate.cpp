#include<bits/stdc++.h>
#define N 109
using namespace std;
typedef long long ll;
ll pos[N], d;

bool ft(int x, int y){
	int f[N];
	for(int i=1; i<N; i++) f[i] = 0;
	f[x] = 1;
	for(int p = x+1; p<=y; p++){
		int cnt = 1;
		while(pos[p] - pos[p - cnt] <= d and p - cnt >= x){
			f[p] += f[p - cnt];
			cnt++;
		}
	}
	if(f[y] == 2) return true;
	return false;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;

	while(t--){
		int n, ans=0;
		bool du[N][N];
		cin >> n >> d;
		for(int i=1; i<=n; i++) cin >> pos[i];
		
		for(int i=1; i<=n-3; i++)
			for(int j=i; j<=n; j++)
				if(ft(i, j)) ans++; 
		
		cout << ans << "\n";
	}
	
	return 0;
}
