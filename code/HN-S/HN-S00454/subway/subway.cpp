#include <bits/stdc++.h>
using namespace std;
int n,m,d,p,a[505000],z[555][505000],t[555][505000],k[555];
int dj[555][555];
void djs(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				dj[i][j]=max(dj[i][j],dj[i][k]+dj[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>z[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			for(int o=1;o<=n;o++){
				dj[i][o]=
			}
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cout<<dj[x][y]+a[x]+a[y];
	}
	return 0;
}
