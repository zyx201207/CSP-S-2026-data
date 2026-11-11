#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll dis[1509][1509],w[1009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m+n;i++)
		for(int j=1;j<=m+n;j++)
			dis[i][j]=-1;
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			dis[m+i][a]=dis[a][m+i]=t;
		}
	}
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				if(dis[i][j]==-1&&dis[i][k]!=-1&&dis[k][j]!=-1) dis[i][j]=dis[i][k]+dis[k][j];
				else if(dis[i][j]!=-1&&dis[i][k]!=-1&&dis[k][j]!=-1){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<endl;
	}
	return 0;
}
