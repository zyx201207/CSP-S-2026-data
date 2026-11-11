#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=507;
const int maxm=5e5+7;
const int inf=1e18+7;
struct node{
	int id,ti;
};
int n,m,q;
int w[maxm];
int dis[maxn][maxn];
vector<node>ve[maxm];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int len=ve[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int u=ve[i][j].id,v=ve[i][k].id;
				dis[u][v]=min(dis[u][v],ve[i][j].ti+ve[i][k].ti);
				dis[v][u]=min(dis[v][u],ve[i][j].ti+ve[i][k].ti);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<"  ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int ID,tt;
			cin>>ID>>tt;
			ve[ID].push_back(node{i,tt});
		}
	}
	init();
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(int i=0;i<ve[x].size();i++){
			for(int j=0;j<ve[y].size();j++){
				int u=ve[x][i].id,v=ve[y][j].id;
//				cout<<u<<"  "<<v<<endl;
				ans=min(ans,dis[u][v]+w[x]+w[y]+ve[x][i].ti+ve[y][j].ti);
			}
		}
//		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
