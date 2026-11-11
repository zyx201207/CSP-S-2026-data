#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f3f3f3fLL;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10) putchar(x+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}
int c,n,m,d,Q,dist[N],k[N],w[N],tot;
bool vis[N];
vector<PII> edges[N];
inline void Dijsktra(int x){
	for(int i=1;i<=tot;i++){
		dist[i]=INF;
		vis[i]=false;
	}
	priority_queue<PII,vector<PII>,greater<PII>> q;
	dist[x]=0;
	q.push({dist[x],x});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(auto y:edges[x]){
			if(dist[y.first]>dist[x]+y.second){
				dist[y.first]=dist[x]+y.second;
				q.push({dist[y.first],y.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),m=read(),n=read(),d=read(),Q=read();
	for(int i=1;i<=n;i++) w[i]=read();
	tot=n;
	for(int i=1;i<=m;i++){
		int cnt=read();
		for(int j=1,last=0;j<=cnt;j++){
			int x=read(),t=read();
			++tot;
			edges[tot].push_back({x,t});
			edges[x].push_back({tot,t});
			if(j!=1){
				edges[tot].push_back({last,0});
				edges[last].push_back({tot,0});
			}
			last=tot;
		}
	}
	while(Q--){
		int s=read(),t=read();
		int ans=w[s]+w[t];
		Dijsktra(s);
		write(ans+dist[t]);
		puts("");
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
