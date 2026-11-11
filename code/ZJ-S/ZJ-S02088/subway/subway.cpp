#include<bits/stdc++.h>
using namespace std;
struct node{
	long long xu,val;
};
struct no{
	long long u,disu;
};
struct tu{
	long long v,w,nxt;
}tr[500010];
long long n,m,c,d,q,head[1010],cn;
long long w[500010],sh[1010][1010],jiyi[1010][1010],dis[1010][1010];
vector<node>mp[500010];
inline bool operator<(no a,no b){
	return a.disu>b.disu;
}
inline long long in(){
	long long x=0;
	char c=' ';
	while(c<'0'){
		c=getchar();
	}
	while(c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline void add(long long u,long long v,long long w){
	tr[++cn]={v,w,head[u]};
	head[u]=cn;
}
inline void dij(long long s){
	bool vis[1010]={0};
	for(int i=1;i<=n;i++){
		dis[s][i]=2e18;
		vis[i]=0;
	}
	dis[s][s]=0;
	priority_queue<no>q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=tr[i].nxt){
			int v=tr[i].v,w=tr[i].w;
			if(!vis[v]&&dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in();n=in();m=in();d=in();q=in();
	for(int i=1;i<=m;++i){
		w[i]=in();
	}
	for(int i=1;i<=n;++i){
		long long k;
		k=in();
		for(int j=1;j<=k;j++){
			long long t,x;
			t=in();x=in();
			mp[t].push_back({i,x});
		}
	}
	for(int i=1;i<=m;i++){
		long long z=mp[i].size();
		for(int j=0;j<z;++j){
			for(int k=j+1;k<z;++k){
				node a=mp[i][j],b=mp[i][k];
				if(!sh[a.xu][b.xu]||sh[a.xu][b.xu]>a.val+b.val){
					sh[a.xu][b.xu]=a.val+b.val;
					sh[b.xu][a.xu]=a.val+b.val;
					add(a.xu,b.xu,sh[b.xu][a.xu]);
					add(b.xu,a.xu,sh[b.xu][a.xu]);
				}
			}
		}
	}
	for(int j=1;j<=n;++j){
		dij(j);
	}
	for(int i=1;i<=q;i++){
		long long s,t,ans=2e18;
		s=in();
		t=in();
		long long z1=mp[s].size(),z2=mp[t].size();
		for(int j=0;j<z1;++j){
			for(int k=0;k<z2;++k){
				ans=min(ans,w[s]+w[t]+mp[s][j].val+mp[t][k].val+dis[mp[s][j].xu][mp[t][k].xu]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} //Âå¹Èbutterhead_lettuce you ren fa xian wo chi 
