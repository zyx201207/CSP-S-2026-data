#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
long long c,n,m,d,q,w[N],a[N][N],t[N][N],dis[2005][2005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++)	cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				dis[j][k]=dis[k][j]=min(dis[j][k],w[j]+w[k]+t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<dis[x][y]<<"\n";
	}
	return 0;
}

