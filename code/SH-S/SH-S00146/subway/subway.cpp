#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=405,N2=5e5+5;
int w[N],f[N][N],a[N],t[N],T[N2][3];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c<=8){
		memset(f,0x3f3f3f3f,sizeof(f));
		for(int i=1;i<=m;i++)f[i][i]=0;
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++)
				cin>>a[j]>>t[j];
			for(int u=1;u<=k;u++)
				for(int v=1;v<=k;v++)
					f[a[u]][a[v]]=min(f[a[u]][a[v]],t[u]+t[v]);
		}
		for(int k=1;k<=m;k++)
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		while(Q--){
			int x,y;
			cin>>x>>y;
			cout<<f[x][y]+w[x]+w[y]<<"\n";
		}
	}
	else if(c==22||c==23){
		/*memset(T,0x3f3f3f3f,sizeof(T));
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1,u,p;j<=k;j++){
				cin>>u>>p;
				T[u][i]=p;
			}
		}
		while(Q--){
			int x,y,ans=1e18;
			cin>>x>>y;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ans=min(ans,T[x][i]+T[y][j]);
				}
			}
			cout<<w[x]+w[y]+ans<<"\n";
		}*/
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
