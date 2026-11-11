#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=1005;
int c,n,m,d,q,k[N],fa[N][M],linenum[M],lines[M][21],a[N][M];
bool is_to[M][M];//是否可达
ll w[M],dis[M][M],t[N][M];//t[i][j]：对于第i条线路的站台，到第j个站厅所需时间
int getfa(int id,int u){
	/*if (fa[id][u]==u)
		return u;
	int v=fa[id][u];
	fa[id][u]=getfa(id,fa[id][u]),disfa[id][u]+=disfa[id][v];
	return fa[id][u];*/
	return (fa[id][u]==u)?u:(fa[id][u]=getfa(id,fa[id][u]));
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if (m>1000)//我不会
		return 0;
	memset(dis,0x3f,sizeof dis);
	for (int i=1;i<=m;i++)
		cin>>w[i],is_to[i][i]=1;
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=m;j++)
			fa[i][j]=j;
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			lines[a[i][j]][++linenum[a[i][j]]]=i;
			for (int o=1;o<j;o++){//直达
				int u=getfa(i,a[i][o]),v=getfa(i,a[i][j]);
				int pj=a[i][j],po=a[i][o];
				if (u!=v)
					fa[i][u]=v;
					//cout<<a[i][o]<<' '<<a[i][j]<<' '<<dis[a[i][o]][a[i][j]]<<' '<<t[i][a[i][o]]<<' '<<t[i][a[i][j]]<<'\n';
					//disfa[i][u]=t[i][a[i][o]]+t[i][a[i][j]];
				dis[po][pj]=min(dis[po][pj],t[i][po]+t[i][pj]);
				dis[pj][po]=min(dis[pj][po],t[i][po]+t[i][pj]);
				is_to[pj][po]=1,is_to[po][pj]=1;
			}
		}
	}for (int o=1;o<=m;o++)//中转
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++)
				if (is_to[o][i]&&is_to[o][j])
				    dis[i][j]=min(dis[i][j],dis[i][o]+dis[o][j]),is_to[i][j]=1;
	while (q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}return 0;
}/*
题目有一点抽象，需要抽象建图(15:54)
Memory:505*500005*(4+8)~2889.66MiB(MLE)
vector优化后:500005*(4+8)~5.722MiB
每个站厅最多引出d个站口，故点数<=22*5*10^5=1.1*10^7，边数<=1.1*10^7
太暴力了，需要优化。(16:14)
使用n个并查集维护从一个站厅可以不换乘到达哪些站厅。
若两个站厅i,j之间可不换乘前往，则最短路可能为min(t[h][i]+t[h][j]);
可以注意到的是不换乘不一定比换乘快。
（注：此处的[i],[j]指第i,j个站厅，不是题目中的意思）
枚举站厅i：O(m)；枚举站厅i的可达站厅：O(m*alpha(m))；
这样，使用O(m^2*alpha(m))的时间，就可以得出每两个可以一次抵达的地铁口之间的最短路。
出现了结果偏大的问题，可能是统计少了。(17:46)
Complete at:18:14
还有两题没时间做了。
score<=144
*/
