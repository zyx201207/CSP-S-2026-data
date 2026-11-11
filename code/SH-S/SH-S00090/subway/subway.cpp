#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXN=5e5+5;
long long ll=1e18;
int k[505];
int w[MAXN];
vector<int>a[505];
vector<int>t[505];
struct node{
	int xian;//属于几号线 
	int time;//到站厅时间 
};
vector<node>bel[MAXN];
long long f[505][505];//从i到j号线最短时间 
int dfs(int x,int y){
	if(f[x][y]==LONG_LONG_MAX){
		;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int t_1,t_2;
			scanf("%d%d",&t_1,&t_2);
			bel[t_1].push_back({i,t_2});
			//a[i].push_back(t_1);
			//t[i].push_back(t_2);
		}
		for(int j=1;j<=n;j++){
			f[i][j]=ll;
			if(i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(bel[i].size()>1)
		for(int j=0;j<bel[i].size();j++){
			for(int k=j+1;k<bel[i].size();k++){
				int x=bel[i][j].xian;
				int y=bel[i][k].xian;
				f[x][y]=min(f[x][y],(long long)(bel[i][j].time+bel[i][k].time));
				f[y][x]=f[x][y];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				f[j][k]=min(f[i][j]+f[i][k],f[j][k]);
				f[k][j]=f[j][k];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=ll;
		for(int i=0;i<bel[x].size();i++){
			for(int j=0;j<bel[y].size();j++){
				int xx=bel[x][i].xian,yy=bel[y][j].xian;
				ans=min((long long)(f[xx][yy]+bel[x][i].time+bel[y][j].time),ans);
			}
		}
		ans+=w[x]+w[y];
		//cout<<x<<' '<<y<<' '; 
		cout<<ans<<endl; 
	}
	return 0;
} 
