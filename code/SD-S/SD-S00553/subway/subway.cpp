#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q,k;
int w[M];
int a[N][N],t[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][k] >> t[i][k];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+t[1][x]+t[1][y];
		cout << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
