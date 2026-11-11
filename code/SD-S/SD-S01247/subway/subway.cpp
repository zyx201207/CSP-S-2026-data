#include <bits/stdc++.h>
#define F(J) for(int j=1;j<=J;++j)
using namespace std;
/*
我敲这玩意暴力都不好打啊
我想想
一定是从某处的地铁口到站厅再到站台
那，Floyd？
dijkstra是单源发不上力
算了先写Floyd再说 
emmm似乎Floyd也有点使不上力气
最小值肯定有w_begin+w_to直接不考虑 
我来想想要从a到b
如果a能直接到b（一条路上）
那就是两端的线路到站厅的距离
如果要中转的话咋办？
我先看看我能不能预处理出两点的最短路
哦……
先把每条线路上两两不同的点距离算出来（起讫点的线路到大厅的距离）
再跑Floyd ！
暴力基本上是 
六百六十六居然还给测试点编号
不过先floyd能过一个算一个吧 
*/
int c,d,n,m,q,w[500500],k[500500],x,y,dis[505][505],aa,tt;
vector<int>a[505],t[505];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	F(m){
		for(int i=1;i<=m;++i){
			dis[i][j]=11451419;
		}
	}F(m){
		cin>>w[j];
	}F(n){
		cin>>k[j];
		for(int i=1;i<=k[j];++i){
			cin>>aa>>tt;
			a[j].push_back(aa);
			t[j].push_back(tt);
		}for(int _i=0;_i<k[j];++_i){
			for(int _j=0;_j<k[j];++_j){
				dis[a[j][_i]][a[j][_j]]=t[j][_i]+t[j][_j];
				dis[a[j][_j]][a[j][_i]]=t[j][_i]+t[j][_j];
				//cout<<a[j][_j]<<'-'<<a[j][_i]<<'='<<dis[a[j][_j]][a[j][_i]]<<endl;
			}
		}
	}//Floyd
	F(m){
		dis[j][j]=0;
	}for(int g=1;g<=m;++g){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				//cout<<'i'<<i<<'g'<<g<<'j'<<j<<'-'<<dis[i][j]<<'<'<<(dis[i][g]+dis[g][j])<<endl;
				dis[i][j]=min(dis[i][j],dis[i][g]+dis[g][j]);
			}
		}
	}F(q){
		cin>>x>>y;
		cout<<(w[x]+w[y]+dis[x][y])<<'\n';
	}
	return 0;
}

