#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+505,M=1e6+5,K=505;
ll dis[K][K];
int D[N],c,n,m,num,q;
vector<int> v[N],w[N];

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>num>>q;
	for(int i=1;i<=m;i++) D[i]=read();
	//记录每一个站台联通哪些站厅 
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),z=read();
			v[x].push_back(i);
			w[x].push_back(z);
		}
	}
	//每一个站厅记录对应站台之间的边
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			if(i!=j) dis[i][j]=1e18;
	for(int i=1;i<=m;i++){
		if(v[i].size()==1) continue;
		for(int j=0;j<v[i].size();j++){
			int x=v[i][j];ll z1=w[i][j];
			for(int k=j+1;k<v[i].size();k++){
				int y=v[i][k];ll z2=w[i][k];
				dis[x][y]=dis[y][x]=min(dis[x][y],z1+z2);
			}
		}
	} 
	//floyd O(n^3) 构建站台之间的最短路
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j || i!=k || j!=k) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	//O(q d^2) 处理询问
	while(q--){
		int x=read(),y=read();ll minn=1e18;
		for(int i=0;i<v[x].size();i++){
			int X=v[x][i];ll z1=w[x][i];
			for(int j=0;j<v[y].size();j++){
				int Y=v[y][j];ll z2=w[y][j];
				minn=min(minn,z1+z2+dis[X][Y]);
			}
		}
		cout<<minn+D[x]+D[y]<<"\n";
	} 
	return 0;
}
/*
肯定要抓住 d<=20 的关键结论 

所以就容易想到 O(nk log k + qd) 的思路：
	先预处理 dis[i][j] 代表 i 站厅到 j 站台的最小代价
	然后每一测就直接找两个点的 j 去做就好了

这样写应该可以过 [1,15] 和 [20,21]
68 分还是非常多的了！我写写写 

但是我们是不是有另外一个思路是直接求出一个站台到另一个站台的距离？ 
我们定义 dis[x][y] 代表 x 站台 => y 站台的最小代价
先 O(n d^2) 的预处理出单个点的，即在站台与站台中连边 
然后 O(n^3) 求出站台的两两最短路
最后 O(q d^2) 枚举答案就好了吧 

通过了所有大样例
开始和刚才写的暴力劲爆对拍 

拍出来错误了
floyd 写错了真没绷住 
*/