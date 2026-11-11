#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 505,MAXM = 5e5 + 5,MAXQ = 1e5 + 5;
int c,n,m,d,q,w[MAXM],k[MAXN],a[MAXN][MAXM],t[MAXM],x[MAXQ],y[MAXQ];
//<(OoO)> 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i) cin >> w[i];
	for(int i = 1;i <= n;++i){
		cin >> k[i];
		for(int j = 1;j <= 2 * k[i];++j) cin >> a[i][j] >> t[j];  
	}
	for(int i = 1;i <= 1;++i){
		cin >> x[i] >> y[i];
		cout << w[i] << '\n';
	}
	return 0;
}
