#include<bits/stdc++.h>
#define int long long
using namespace std;
const int xx=1e6+5e2;
const int mod=998244353;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
struct node{
	int nex,fro,to,val; 
}e[xx<<1];
int he[xx],tot;
void add(int u,int v,int w){
	e[++tot].nex=he[u];
	e[tot].fro=u;
	e[tot].to=v;
	e[tot].val=w;
	he[u]=tot;
}
int n,d,x[xx];
int dist[xx],cnt[xx];
void dijkstra(int s){
	for(int i=1;i<=n;++i){
		dist[i]=0x3f3f3f3f;
		cnt[i]=0;
	}
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	cnt[s]=1;
	while(q.size()){
		auto now=q.top();
		q.pop();
		int dis=now.first,u=now.second;
		if(dis!=dist[u]) continue;
		for(int i=he[u];i;i=e[i].nex){
			int v=e[i].to,w=e[i].val;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u];
				q.push({dist[v],v});
			}
			else if(dist[v]==dist[u]+w){
				cnt[v]+=cnt[u];
			}
		}
	}
}
void solve(){
	n=read(),d=read();
	tot=0;
	for(int i=1;i<=n;++i){
		he[i]=0;
	}
	for(int i=1;i<=n;++i){
		x[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(i==j) continue;
			if(abs(x[i]-x[j])<=d){
				add(i,j,1);
				add(j,i,1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		dijkstra(i);
		for(int j=1;j<=n;++j){
			//cout<<i<<' '<<j<<' '<<dist[j]<<' '<<cnt[j]<<'\n';
			if(i==j) continue;
			if(cnt[j]==2){
				ans++;
			}
		}
	}
	cout<<ans/2<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1,c;
	cin>>c>>T;
	while(T--){
		solve();
	}
}

