//long long
//清空文件夹其他文件
//freopen!!!文件名+别注释 
//线段树开4倍，双向边开2倍，不同点组开总点数倍，小心N的+10和循环上界，小心越界，未定义行为!!! 
//别用endl 
//考虑各种特例 
//初始化问题!!  
//多测清空!!!
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

const int N=666;
const int M=5e5+10; ///////////////////////////

int cnum,n,m,d,q; 

long long kk[N];
long long w[M];
long long dis[N][N];

//int head[M];
//struct Edge{
//	int next,to;
//	long long val;
//}e[M<<1];/////////////////////////////////////
//
//int tote=0;
//void add_edge(int from,int to,long long val){
//	++tote;
//	e[tote].next=head[from];
//	head[from]=tote;
//	e[tote].to=to;
//	e[tote].val=val;
//	return ;
//}

struct Node{
	int id;
	long long sm;
};
vector<Node> stt[M];//地铁站 

//priority_queue< pair<long long,int>, vector< pair<long long,int> >, greater< pair<long long,int> > > pq;

//void ceshi(){
//	cin>>n;
//	long long x;
//	for(int i=1;i<=n;++i){
//		cin>>x;
//		pq.push({x,i});
//	}
//	while(!pq.empty()){
//		pair<long long,int> nw=pq.top();
//		pq.pop();
//		cout<<nw.second<<' '<<nw.first<<'\n';
//	}
//	return ;
//	/*
//	
//	5
//	100 24 91 13 78
//	
//	*/
//}

//bool visd[N];
//
//void Djikstra(int st){
//	
//	pq.push({0,st});
//	
//	for(int i=1;i<=n;++i) visd[i]=false;
//	
//	while(!pq.empty()){
//		int nw=pq.top().second();
//		pq.pop();
//		if(visd[nw]) continue;
//		visd[nw]=true;
//		for(int i)
//	}
//	
//}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	ceshi();
//	return 0;
	
	memset(dis,0x3f,sizeof(dis));
	
	cin>>cnum>>n>>m>>d>>q;
	
	for(int i=1;i<=m;++i){
		cin>>w[i]; 
	}
	
	int gll;
	long long tmm;
	for(int i=1;i<=n;++i){
		cin>>kk[i];
		for(int j=1;j<=kk[i];++j){
			cin>>gll>>tmm;
			stt[gll].push_back({i,tmm});
		}
	}
	
	for(int i=1;i<=m;++i){
		int len=stt[i].size();///////////////////
		for(int j=0;j<len;++j){
			for(int k=0;k<len;++k){
				Node jj=stt[i][j];
				Node kk=stt[i][k];
				if(j!=k)
					dis[jj.id][kk.id]=min(dis[jj.id][kk.id],jj.sm+kk.sm);
					dis[kk.id][jj.id]=dis[jj.id][kk.id];
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		dis[i][i]=0;
	}
	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	int st,ed;
	long long ans;
	for(int i=1;i<=q;++i){
		cin>>st>>ed;
		int lens=stt[st].size();
		int lent=stt[ed].size();
		ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<lens;++j){
			for(int k=0;k<lent;++k){
				Node jj=stt[st][j];
				Node kk=stt[ed][k];
				ans=min(ans,jj.sm+kk.sm+dis[jj.id][kk.id]);
			}
		}
		cout<<ans+w[st]+w[ed]<<'\n';
		
	}
	
	return 0;
} 
