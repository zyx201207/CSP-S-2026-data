#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using PII=pair<ll,int>;
const int maxn=5e5+10;
const ll INF=1e18;
int c,n,m,d,q;
struct Edge{
	int to,w,nxt;
}e[maxn*2];
int head[maxn],cnt;
ll dis[maxn];
int w[maxn],k[maxn],a[maxn],t[maxn];
ll ans=0;
inline ll read(){
	ll r=0;int f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}while(isdigit(c)){
		r=r*10+(c-'0');
		c=getchar();
	}return r*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}if(x>9){
		write(x/10);
	}putchar(char(x%10+'0'));
}
void init(){
	memset(head,-1,sizeof head);
	fill(dis,dis+n+1,INF);
	cnt=0;
}
void add(int u,int v,int w){
	e[cnt]={v,w,head[u]};
	head[u]=cnt++;
}
ll lucheng(int be,int en){
	init();
	ll ans=w[be]+w[en];
	priority_queue<PII,vector<PII>,greater<PII>> pq;
	for(int j=1;j<=k[be];j++){
		pq.push({0,a[j]});
		while(!pq.empty()){
			int u=pq.top().second;
			int d=pq.top().first;
			pq.pop();
			if(dis[u]<d)continue;
			for(int k=head[u];k!=-1;k=e[k].nxt){
				int v=e[k].to;
				int w=e[k].w;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					pq.push({dis[v],v});
				}
			}
		}
	}
	
	
	
	
	return ans+dis[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			//int a,t;
			a[j]=read(),t[j]=read();
			add(i,a[j],t[j]);
			add(a[j],i,t[j]);
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		x=read(),y=read();
		write(lucheng(x,y));
		putchar('\n');
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
