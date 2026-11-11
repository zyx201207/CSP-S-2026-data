#include<bits/stdc++.h>
using namespace std;
const int N=500,M=1000;
int c,n,m,d,q;
long long w[M];
int vis[M];
long long a[M][M],t[M][M];
long long fl[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	memset(t,-1,sizeof(t));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			fl[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			vis[a[i][j]]++;
		}
		for(int j=1;j<=k;j++){
			for(int g=1;g<=k;g++){
				fl[a[i][j]][a[i][g]]=t[i][a[i][j]]+t[i][a[i][g]];
				fl[a[i][g]][a[i][j]]=t[i][a[i][j]]+t[i][a[i][g]];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << fl[x][y]+w[x]+w[y] << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
