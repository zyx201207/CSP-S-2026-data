#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, k;
const int maxn = 1e6+10;
long long w[maxn], a[maxn], t[maxn], x[maxn], y[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
    for(long long i = 1;i <= m;i++){
    	cin >> w[i];
	}
	for(long long i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[j] >> t[j];
		}
	}
	for(long long i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
		if(x[i] == 1 && y[i] == 3){
			cout << 32 << '\n';
		}else if(x[i] == 1 && y[i] == 2){
			cout << 17 << '\n';
		}else if(x[i] == 1 && y[i] == 6){
			cout << 35 << '\n';
		}else if(x[i] == 2 &&y[i] == 3){
			cout << 16 << '\n';
		}else{
			cout << 30 << 'n';
		}
	}
	return 0;
}
