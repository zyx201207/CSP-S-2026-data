#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
int w[M];
map<pair<int,int>,bool> f;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(d<=2){

	}
	if(c<=3&&c>0){
		int dis[205][205];
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			int k,s;
			cin>>k;
			for(int j=1;j<=k;j++){
				int v,cost;
				cin>>v>>cost;
				if(j==1) s=v;
				dis[i*m+s][i*m+v]=dis[i*m+v][i*m+s]=0;
				dis[i*m+v][v]=dis[v][i*m+v]=cost;
			}
		}
		for(int i=1;i<=(n+1)*m;i++) dis[i][i]=0;
		for(int k=1;k<=(n+1)*m;k++)
			for(int i=1;i<=(n+1)*m;i++)
				for(int j=1;j<=(n+1)*m;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int i=1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			cout<<w[l]+w[r]+dis[l][r]<<endl;
		}
		return 0;
	}
	if(c<=8&&c>=7){
		int dis[3005][3005];
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			int k,s;
			cin>>k;
			for(int j=1;j<=k;j++){
				int v,cost;
				cin>>v>>cost;
				if(j==1) s=1;
				dis[m+(i-1)*2+s][m+(i-1)*2+j]=dis[m+(i-1)*2+j][m+(i-1)*2+s]=0;
				dis[m+(i-1)*2+j][v]=dis[v][m+(i-1)*2+j]=cost;
			}
		}
		for(int i=1;i<=m+n*2;i++) dis[i][i]=0;
		for(int k=1;k<=m+n*2;k++)
			for(int i=1;i<=m+n*2;i++)
				for(int j=1;j<=m+n*2;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int i=1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			cout<<w[l]+w[r]+dis[l][r]<<endl;
		}
		return 0;
	}
	if(c==20||c==21||n==2){
	}
	return 0;
}
