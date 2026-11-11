#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[500500],t,a,b,x,y;
long long dist[600][600],ans;
vector<int> ve[500500],wi[500500];
//ve[i]表示站台i能去到的线路 
//5e5条线路，每条20站，最多1e7条边 
//1e5次询问，每次必须O(1)/O(n)/O(logm)/O(d*d)复杂度,需要预处理

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		for(int j=1;j<=t;j++){
			scanf("%d%d",&a,&b); 
			for(int k=0;k<ve[a].size();k++){
				dist[ve[a][k]][i]=dist[i][ve[a][k]]=wi[a][k]+b;
			}
			ve[a].push_back(i);
			wi[a].push_back(b);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ans=4e18;
		for(int i=0;i<ve[x].size();i++){
			for(int j=0;j<ve[y].size();j++){
				ans=min(ans,dist[ve[x][i]][ve[y][j]]+wi[x][i]+wi[y][j]);
			}
		} 
		printf("%lld\n",ans+w[x]+w[y]);
	} 
	return 0;
} 
