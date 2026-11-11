#include <bits/stdc++.h>
using namespace std;
const int N=500;
int c,n,m,d,q;
int w[N],ki[N],a[N][N],t[N][N],dis[N][N],mp[N][N];
/*
A:一个线路直接退化成边，强行把点加到边上
B：也就是说换乘次数尽可能少 
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	bool A=1;
	for(int i=1;i<=n;i++){
		cin>>ki[i];
		if(ki[i]>2)A=0;
		for(int j=1;j<=ki[i]*2;j++)cin>>a[i][j]>>t[i][j];
	}
	if(A==1){
		memset(mp,127,sizeof(mp));
		cout<<mp[1][1]<<"\n";
		for(int i=1;i<=n;i++){
			if(ki[i]==2){
				mp[a[i][1]][a[i][2]]+=t[i][a[i][2]];
				mp[a[i][2]][a[i][1]]+=t[i][a[i][1]];
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
}

