#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
int c,n,m,d,q;
int f[5000][5000],w[5000],k,t[5000],a[5000],inf = 1e9;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++){
			f[i][j] = inf;
		}
		f[i][i] = 0;
		cin >> w[i];
	}
	for(int i = 0;i<n;i++){
		cin >> k;
		for(int j = 0;j<k;j++){
			cin >> a[j] >> t[j];
		}
		for(int j = 0;j<k;j++){
			for(int l = 0;l<k;l++){
				if(f[a[j]][a[l]] > t[j]+t[l]){
					f[a[j]][a[l]] = t[j]+t[l];
				}
				if(f[a[l]][a[j]] > t[j]+t[l]){
					f[a[l]][a[j]] = t[j]+t[l];
				}
			}
		}
		//bianquan
	}
	for(int k = 1;k<=m;k++){
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=m;j++){
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);		
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << f[x][y]+w[x]+w[y] << "\n";
	}
	return 0;
}
