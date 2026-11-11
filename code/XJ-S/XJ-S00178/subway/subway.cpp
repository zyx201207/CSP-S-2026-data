#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int w[m];
	for(int i=0;i<m;i++) cin >> w[i];
	int k[n], a[n][400], t[n][400];
	for(int i=0;i<n;i++){
		cin >> k[i];
		for(int j=0;j<k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	int x[q], y[q];
	for(int i=0;i<q;i++) cin >> x[i] >> y[i];
	
	int time[q] = {0};
	for(int i=0;i<q;i++){
		time[i] += w[x[i]-1] + w[y[i]-1];
	}
	
	int v = 0, s = 0;
	while(s != q){
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				if(a[i][j] <= y[s]) v += t[i][j];
			}
		}
		
		time[s] += v;
		v = 0;
		s ++; 
	}
	
	for(int i=0;i<k[n-1];i++){
		if(a[n-1][i] == y[q-1]) time[q-1] -= t[n-1][i];
	}
	
	for(int i=0;i<q;i++) cout << time[i] << endl;
	
	return 0;
}
