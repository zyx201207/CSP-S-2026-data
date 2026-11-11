#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1005;
//long long ans=1005;
int c,n,m,d,q,w[N],k;
int x,y;
long long f[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			if(i==j) f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
//			cout<<t;
			f[m+i][a]=t;
			f[a][m+i]=t;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}