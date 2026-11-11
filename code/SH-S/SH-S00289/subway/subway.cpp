#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
long long kou_ting[100005];//¿Ú->Ìü
long long side[1005][1005];
long long t[505][1005];
int p[1005];
long long dis[1005][1005];
void F(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=side[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			side[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++) cin>>kou_ting[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>p[j];
			cin>>t[i][p[j]];
		}
		for(int j=1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				side[p[j]][p[k]]=min(side[p[j]][p[k]],t[i][p[j]]+t[i][p[k]]);
				side[p[k]][p[j]]=side[p[j]][p[k]];
				//cout<<side[p[j]][p[k]]<<" ";
			} 
		}
	}
	F();
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+kou_ting[x]+kou_ting[y];
		cout<<endl;
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	
	return 0;
}
