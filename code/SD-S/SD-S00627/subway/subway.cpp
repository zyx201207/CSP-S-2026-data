#include<bits/stdc++.h>
using namespace std;
bool b = 0, k;
long long c, n, m, d, q;
struct bh{
	long long id, u;
}o[5145140];
long long w[5145140], a[520][5145140], t[520][5145140], x[5145140], y[5145140];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i]; 
	}
	for(int i = 1; i <= q; i++){
		cin >> k;
		if(k > 2) b = 1;
		for(int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
			o[a[i][j]].u ++;
			if(k == 0){
				o[a[i][j]].id = i;
			}
		}
		cin >> x[i] >> y[i];
	}
	if(b == 0){
		for(int i = 1; i <= q; i++){
			
		if(o[x[i]].id == o[y[i]].id){
			cout << t[i][y[i]] + w[x[i]];
		}
		else if(o[x[i]].u == 2 || o[y[i]].u == 2){
			cout << t[i][y[i]] + w[x[i]] ;
		}
		else{
			cout << t[i][(x[i] + 1) % 2] + w[x[i]] + t[i][(x[i ]+ 1)% 2];
		}
		}
	}
	return 0;
}

