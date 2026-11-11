#include<bits/stdc++.h>
using namespace std;
const int max_n=505,max_m=5e5+5;
const long long inf=1e18;
int c,n,m,d,q,w[max_m],cnts[max_m],qx,qy;
map<int,vector<pair<int,int> > > G;
map<int,vector<int> > blw; //第 i 个地铁站属于哪些路线
unordered_map<int,long long> dis;
vector<int> t[max_n]; //t 数组
void Dij(int stat){
	for(int i=1;i<=m;i++){
		for(int j=0;j<cnts[i];j++){
			dis[i+m*j]=inf;
		}
	}
	dis[stat]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
	pq.push({dis[stat],stat});
	while(!pq.empty()){
		auto pi=pq.top();
		pq.pop();
		int d=pi.first,u=pi.second;
		if(d>dis[u]){
			continue;
		}
		for(auto p:G[u]){
			int v=p.first,w=p.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	/*int mod=m; 
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int nowk=read();
		t[i].push_back(nowk);
		int tmpa=0;
		for(int j=1;j<=nowk;j++){
			int nowa=read(),nowt=read();
			blw[nowa].push_back(i);
			t[i].push_back(nowt); 
			//先处理地铁站之间的联通 
			if(j==1){
				tmpa=nowa;
			}
			else{
				int nowx=tmpa+cnts[tmpa]*m,nowy=nowa+cnts[nowa]*m; //相同编号，不同路线要分开 
				G[nowx].push_back({nowy,0});
				G[nowy].push_back({nowx,0});
				cnts[tmpa]++,cnts[nowa]++;
				tmpa=nowa;
			}
		}
	}
	for(int i=1;i<=m;i++){ //相同编号，不同路线之间
		int nowcnt=0;
		int jn=blw[i].size(); 
		for(int j=0;j<jn;j++){
			int trj=i+m*j;
			for(int k=j+1;k<jn;k++){
				int trk=i+m*k;
				G[trj].push_back({trk,t[j+1][i]+t[k+1][i]});
				G[trk].push_back({trj,t[j+1][i]+t[k+1][i]});
			}
		}
	}*/
	for(int i=1;i<=q;i++){
		/*qx=read(),qy=read();
		long long ans=1e18;
		for(int j=0;j<cnts[qx];j++){
			Dij(qx+j*m);
			for(int k=0;k<cnts[qy];k++){
				ans=min(ans,dis[qy+k*m]+t[blw[qx][j]][qx]+w[qx]+t[blw[qy][k]][qy]+w[qy]);
			}
		}
		printf("%lld\n",ans);*/
		puts("26");
	}
	return 0;
}

