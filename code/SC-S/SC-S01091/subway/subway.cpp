#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
struct Edge{
	int to,next;
}e[N<<2];
int head[N<<2],cnt;
void adde(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool onit[5005][5005];
int t[5005][5005];//t[i][j]第i个点在第j条路线上站台所需时间
vector<int> ve[5005];
bool vis[5005];
int ans;
void dfs(int u,int fa,int en,int dep,int road){
//	cout<<"now road is "<<road<<endl;
//	cout<<fa<<"->"<<u<<' '<<dep<<endl;
	if(u==en){
		ans=min(ans,dep+t[en][road]);
		return;
	}
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(!vis[v]){
			vis[v]=1;
			if(onit[v][road]==1){
				dfs(v,u,en,dep,road);
			}else{
				for(int i=0;i<ve[v].size();i++){
					if(onit[u][ve[v][i]]){
						dfs(v,u,en,dep+t[u][road]+t[u][ve[v][i]],ve[v][i]);
					}
				}
			}
			vis[v]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[405];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[a[j]][i];
			if(j>=2){
				adde(a[j-1],a[j]);
				adde(a[j],a[j-1]);
			}
			onit[a[j]][i]=1;
			ve[a[j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int st,en;
		scanf("%lld %lld",&st,&en);
		ans=INT_MAX;
		memset(vis,0,sizeof vis);
		for(int i=0;i<ve[st].size();i++){
			dfs(st,0,en,t[st][ve[st][i]],ve[st][i]);
		}
		printf("%lld\n",ans+w[st]+w[en]);
	}
	return 0;
}
/*
48分钟T1过大样例，优势在我
这道题的题面好复杂啊
不着急，沉下心来慢慢读
题外话：
T1 蜗蜗的能量水晶
T2 蜗蜗的出行计划
T3 蜗蜗的双径岛屿
T4 蜗蜗的研发基地
绷
注意到没有说步行到另一个站台
所以我们只需要考虑在地铁站里穿梭的最小时间
有点难啊我们查询至少要做到O(nlogn)
bur，你的意思是，同一个站在不同的路线上走到站台的时间不一样吗？
666无敌了
感觉正解比较困难，想想特殊性质
说不定提示正解呢对不对
先来想暴力
显然直接从起点开始深搜是容易的
完蛋了这个东西怎么还有环啊
小数据的话，我们是否可以直接预处理任意两个站台的最短时间？
设dp[i][j]表示从i到j的最短时间？
转移|困难
不行啊两个站通行可能要换乘很多路线啊
不管了先来写深搜的
甚至数据都不是很好存储
不好笑，我觉得T3比这道题可做
行还好暴力是对的
*/
/*
文明与道德被埋葬在黎明前，踽行于无止境的风雪之中，伊塔库亚早已忘了自己为谁守夜
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/