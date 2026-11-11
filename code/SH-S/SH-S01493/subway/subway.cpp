#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5*1e6;
int c,n,m,d,q;
int mint[maxn][maxn];
int w[maxn],k[maxn],a[maxn][maxn],t[maxn][maxn],x[maxn],y[maxn];
void dfs(int tmp,int xian,int cost){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[n];j++){
			if(a[i][j]==tmp){
				if(i==xian){
					mint[i][j]
					dfs(a[i][j+1],xian,cost);
				}
				else{
					dfs(a[i][j+1],i,cost+t[xian][j]+t[i][j]);
				}
			}
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++) cin >> a[i][j] >> t[i][j];
	}
	dfs(1,1,0);
	for(int i=1;i<=q;i++){
		cin >> x[i] >> y[i];
		cout << w[x[i]]+w[y[i]]+mint[i][j]+t[];
	}
	
	return 0;
}
