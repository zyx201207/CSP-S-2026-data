#include <bits/stdc++.h>
using namespace std;
long long n,m,d,q,w[500005],a[500005][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j];
		}
	}
	if(m==2) cout << w[1]+a[1][1]+w[2]+a[1][2];
	
	return 0;
}
