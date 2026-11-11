#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	int a[n];
	int e[n][n];
	for(int i = 1; i <= n; i++){
		cin >> a[i];	
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j > i && a[j] - a[i] <= m){
				e[i][j] = a[j] - a[i];
			}else{
				e[i][j] = 0;
			}
		}
	}
	int g = 0, h = 0;
	for(int i = 1; i <= n; i++){
		int cnt = 0, k = m;
		for(int j = n; j >= 1; j--){
			if(e[j][i] != 0 && k - e[j][i] >= 0){
				cnt += 1;
				k = k - e[j][i];
			}
		}
		if(cnt > g){
			h = i;
			g = cnt;
		}
	}
	int js = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == a[h]){
			js++;
		}
	}
	cout << g + js;

	return 0;
}

