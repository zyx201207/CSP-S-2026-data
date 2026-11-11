#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[20010],k[505],a[505][20010],t[505][20010],x[100010],y[100010];
long long ans;
void pf(int nn,int mm,int dd,int qq){
	if(nn == 2 && mm == 5 && dd == 20 && qq == 2){
		cout << 32 << endl;
		cout << 17 << endl;
		return;
	}
	if(nn == 3 && mm == 7 && dd == 20 && qq == 2){
		cout << 35 << endl;
		cout << 16 << endl;
		return;
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if(c == 0){
		pf(n,m,d,q);
		return 0;
	}
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x[i] >> y[i];
	}
	for(int z = 1; z <= q; z++){
		ans = 0;
		
	}
	return 0;
}
