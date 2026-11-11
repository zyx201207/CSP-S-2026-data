#include<bits/stdc++.h>
using namespace std;
long long c/*测试点编号*/,m/*地铁路线数 500*/,n/*地铁站数 <10^5 所有路线的过的站点数量加起来不超过5*10^5*/,d/*最大入度+出度 20*/,q/*组数 10^5*/;
long long w[500005]/*入栈口到站厅*/;
struct noode{
	long long u;
	long long t;
};
//vector<node> ro[505];//存路线！！！附录：存个锤子！！！ 
long long k[500005];

struct node{
	long long v;
	long long w;
};
vector<node> e[520005];
long long ans[510005],vis[520005];

queue<long long> que; 
long long djistla(long long s,long long z){
	long long sum=0;
	for(long long i=1;i<=n+m;i++){
		ans[i]=1000000;
		
	}
	ans[s]=0;
	que.push(s);
	while(!que.empty()){
		long long u=que.front();
		que.pop();
		vis[u]=0;
		for(node t:e[u]){
			if(ans[t.v]>ans[u]+t.w){
				ans[t.v]=ans[u]+t.w;
				if(vis[t.v]==0){
					vis[t.v]; 
					que.push(t.v);
				}
			}
		}
	}
	
	return ans[z];
}//这个是spfa 

//struct Node{
//	long long u;
//	long long dis;
//	bool operator <(const Node p) const{
//		if(vis[u]!=vis[p.u]){
//			return vis[u]<vis[p.u];
//		}
//		return dis<p.dis;
//	}
//};
//priority_queue<Node> que; 
//long long djistla(long long s,long long z){
//	long long sum=0;
//	for(long long i=1;i<=n;i++){
//		ans[i]=1e9;
//		
//	}
//	ans[s]=0;
//	que.push({s,0});
//	for(long long i=1;i<=n+m;i++){
//		Node aaa=que.top();
//		long long u=aaa.u;
//		vis[u]=1;
//		que.pop();
//		for(node t:e[u]){
//			if(ans[t.v]>ans[u]+t.w&&!vis[t.v]){
//				ans[t.v]=ans[u]+t.w;
//				que.push({t.v,ans[t.v]});
//			}
//		}
//	}
//	return ans[z];
//}//这个是dj 
void solveminrow(){
	//下面是神秘最短路算法！！！ 
	for(long long i=1;i<=m;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			noode rr;
			cin>>rr.u>>rr.t;
			e[rr.u].push_back({n+i,rr.t});
			e[n+i].push_back({rr.u,rr.t});
		}
	}

	return;
}

void solvespa(){
    long long aaa[5];
	for(long long i=1;i<=m;i++){
		cin>>k[i];
		long long sum=0;
		for(long long j=1;j<=k[i];j++){
			noode rr;
			cin>>rr.u>>rr.t;
			aaa[j]=rr.u;
			sum+=rr.t;
		}
		if(k[i]!=2){
			continue;
		}
		e[aaa[1]].push_back({aaa[2],sum});
		e[aaa[2]].push_back({aaa[1],sum});
	}
	m=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(long long i=1;i<=n;i++){
		cin>>w[i];
	}
	
//	for(long long i=1;i<=m;i++){
//		cin>>k[i];
//		for(long long j=1;j<=k[i];j++){
//			noode rr;
//			cin>>rr.u>>rr.t;
//			e[rr.u].push_back({n+i,rr.t});
//			e[n+i].push_back({rr.u,rr.t});
//		}
//	}
	if(c>=7&&c<=11){
		solvespa();
	}else{
		solveminrow();
	}
	
	for(long long i=1;i<=q;i++){
		long long xx,yy;
		cin>>xx>>yy;
		cout<<djistla(xx,yy)+w[xx]+w[yy]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

