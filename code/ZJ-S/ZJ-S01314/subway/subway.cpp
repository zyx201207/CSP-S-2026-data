//把线路看成点，把地铁站看成边 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
const int M=5e5+5;
vector<PLL>v[M];//经过该地铁站的所有地铁线路(first)及线路走到站厅的时间(second)（用作更新线路间的最短路） 
int num,n,m,ddd,q,k,x,y,a;//k为线路内地铁站总数，将一条线路看作一个点 
LL w[M],t,d[505][505]={};//d为线路i到线路j的最短路 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&num,&n,&m,&ddd,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d %lld",&a,&t);
			v[a].push_back({i,t});
		}
	} 
	//预处理：遍历m个地铁站，从线路i到线路j的最短路 
	//先给d初始化一下
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(i!=j)
			d[i][j]=1e18; 
	//预处理第一步：遍历m个地铁站根据站台走到站厅时间初始化d
	for(int i=1;i<=m;i++)
	for(PLL Station_x:v[i])
	for(PLL Station_y:v[i])
	if(Station_x.first!=Station_y.first)
	d[Station_x.first][Station_y.first]=min(d[Station_x.first][Station_y.first],Station_x.second+Station_y.second);
	//预处理第二步：类似多源最短路通过换乘更新d，进一步缩短n个线路的最短距离
	for(int k=1;k<=n;k++) 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j&&i!=k&&j!=k)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	//处理询问 
	while(q--){
		scanf("%d %d",&x,&y);
		LL ans=1e18;
		for(PLL Station_x:v[x])
		for(PLL Station_y:v[y])
		ans=min(ans,Station_x.second+Station_y.second+d[Station_x.first][Station_y.first]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
