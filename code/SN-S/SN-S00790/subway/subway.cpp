#include<bits/stdc++.h>
using namespace std;
//w1是地铁口到站厅的距离；w是过点距
//c是测试点编号
//n是线路数
//m是地铁站数
//d是地铁站最大线路数
//q时出行计划数
//z是站点路线个数 z2记录站
long long c,n,m,d,p,w1[500007],w[500007],z[500007];
vector<int > z2[500007],a2[500007];
int zk[500007];
struct dt {
	//zh:站点，xi:线路
	int zh,xi;
};
long long sum[500007];
//map(int,int) far;
//邻接表a存地图 和所在线路
vector<dt> a[500007] ;
priority_queue<int > q;
bool vis[500007];
void dli(int u) {
	memset(sum,0x3f,sizeof(sum));
	memset(vis,0,sizeof(vis));
	q.push(u);
	vis[u]=1;
	sum[u]=0;
	while(!q.empty()) {
		int u=q.top();
//		cout<<sum[u]<<' '<<u<<endl;
		q.pop();
		for(int i=0; i<a2[u].size(); i++) {
			int y=a2[u][i];
			if(vis[y]!=1) {
				if(sum[y]!=0x3f3f3f3f)
					sum[y]=min(sum[y],sum[u]+w[y]);
				else
					sum[y]=0;
				cout<<sum[2]<<endl;
				q.push(y);
				vis[y]=1;
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
//rd是 记录线路;w2是站厅到站台的距离
	int w2[m+7][n+7],rd[n+7][m+7];
	for(int i=1; i<=m; i++) {
		cin>>w1[i];
//		cout<<"yyyyy ";
	}
	for(int i=1; i<=n; i++) {
		//k是当前线路站点数；
		int k;
		cin>>k;
		zk[i]=k;
//		cout<<"yyyyy ";
		for(int j=1; j<=k; j++) {
			cin>>rd[i][j];
			cin>>w2[rd[i][j]][i];
			z[rd[i][j]]++;
			z2[rd[i][j]].push_back(i);
//			cout<<"yyyyy ";
		}

	}
	for(int i=1; i<=n; i++) {
		if(z[i]>1) {
			for(int j=0; j<z2[i].size(); j++) {
				int x=z2[i][j];
				w[i]+=w2[i][x];
//				cout<<w[i]<<" "<<i<<endl;
				for(int l=1; l<=zk[x]; l++) {
					int h=rd[x][l];
					if(z[h]>1) {
						a2[i].push_back(h);
						a2[h].push_back(i);
					}

				}
			}
		}
	}
//cout<<w[2]<<endl;
	for(int i=1; i<=p; i++) {
		int u,v;
		cin>>u>>v;
		dli(u);
		cout<<sum[2]+w1[u]+w1[v]<<endl;
//cout<<<<endl;
	}
//
	return 0;
}
