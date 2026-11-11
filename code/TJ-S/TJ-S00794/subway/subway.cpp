#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,d,T;
int dis[505][505];
int foot[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>foot[i];
		dis[i][i]=0;
	}
	int stain[505]={0},w[505]={0};
	for(int f=1;f<=n;f++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>stain[i]>>w[i];
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				dis[stain[i]][stain[j]]=w[i]+w[j];
				dis[stain[j]][stain[i]]=w[i]+w[j];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(T--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+foot[x]+foot[y]<<'\n';
	}
	return 0;
}


