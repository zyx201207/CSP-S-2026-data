#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int a[N][N];
int t[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=2*k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	int i=1;
	while(q--){
		cout << t[i][j]*(++i)+w[1]+w[n] << endl;
	}
	return 0;
}
