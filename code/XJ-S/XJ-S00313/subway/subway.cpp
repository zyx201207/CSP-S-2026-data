#include<bits/stdc++.h>
#define Elysia return
//冬冬猫的代码
//T2
using namespace std;
typedef long long LL;
const int N=510,M=5e5+10,Q=1e5+10;
int c,n,m,d,p,q;
int w[M],k[N];
int a[N][N],t[N][N];
int x[N],y[N];
int h[N],e[N*2],ne[N*2],col[N*2],idx;
//col用来标记这个是第几个地铁线路的阿巴阿巴

void add(int a,int b,int c){
	e[idx]=b,ne[idx]=h[a],col[idx]=c,h[a]=idx++;
} 
struct Node{
	int u,val,col;
};
bool vis[N];
int ans;
void solve(int st,int en){
	ans=1e9;
	memset(vis,0,sizeof(vis));
	queue<Node> q;
	for(int i=h[0];~i;i=ne[i]){
		if(e[i]==st){
			q.push({e[i],w[e[i]]+t[e[i]][1],e[i]});
//			w1 + t1,1
		}
	}
	while(q.size()){
		Node res=q.front();
		q.pop();
		for(int i=h[res.u];~i;i=ne[i]){
			int j=e[i];
//			cout<<res.u<<" "<<j<<"\n";
			if(vis[j]||j==0)continue;
			int co=col[i];
				if(j==en){
					ans=min(ans,res.val+w[j]+t[res.u][j]);
					continue;
				}
			if(co!=res.col){
				q.push({j,res.val+t[res.u][j]+t[j][j],co});			
			}
			else{
				q.push({j,res.val,co});
			}
		}		
		vis[res.u]=true;

	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
//	std::ios_with_stdio(false);
	std::cin.tie(false);
	std::cout.tie(false);
	memset(h,-1,sizeof(h));
	
	cin>>c>>n>>m>>d>>q;
/*
n 地铁线路数
m 地铁站数
d 每个地铁站最多被几条线路经过
q 出行计划数
*/

	for(int i=1;i<=m;i++){
		cin>>w[i];
// wi 从每个地铁站的地铁口走到站厅需要的时间
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
//ki 第 i 条线路经过的地铁站数 
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				add(a[i][j],a[i][j-1],i);
				add(a[i][j-1],a[i][j],i);
			}
			else{
				add(a[i][j],0,i);
				add(0,a[i][j],i);				
			}
		}
/*
ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
*/
	}
//	for(int i=h[2];~i;i=ne[i]){
//		int j=e[i];
//		cout<<j<<"\n";
//	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		solve(x[i],y[i]);
		cout<<ans<<"\n";
//分别表示第 r 个出行计划的起点和终点所在的地铁站编号
	}
	Elysia 0;
}
/*
SOS这个题目有点长了吧

就是乘坐地铁从A到B

可能要换站

换站就要+目前地铁站台到目标站厅 + 目标站厅到目标地铁口

然后求最小值

特殊性质A每个线路最多经过两个 额 就是换站是唯一确定的？只需要模拟，到不了就只能换唯一确定的站


特殊性质B时间一模一样 额 所以bfs？ 
 
*/
