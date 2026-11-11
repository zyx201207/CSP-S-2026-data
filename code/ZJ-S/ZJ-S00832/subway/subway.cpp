#include<bits/stdc++.h>
using namespace std;
const long long maxn=500000,maxm=500,maxd=25,inf=LLONG_MAX;
int n;
long long c,m,d,q,a[maxn+5],tu,tv;
struct Node{
	int u;
	long long w;
	bool operator <(Node x)const{
		return w>x.w;
	}
}s[maxn+5];
struct Edge{
	int v;
	long long w;
};
vector<Edge> e[maxn+maxm+5];
long long f[maxn+maxm+5];
priority_queue<Node,vector<Node> > qu;
bool vis[maxn+maxm+5];
int es[maxn+maxm+5];
struct Quest{
	int u,v,num,res;
}quest[100005];
bool cmpu(Quest x,Quest y){
	return x.u<y.u;
}
bool cmpnum(Quest x,Quest y){
	return x.num<y.num;
}
void dijkstra(int p,int cur){
//	cout<<p<<endl;
//	memset(f,0x7f,sizeof(f));
//	memset(vis,0,sizeof(vis));
	f[p]=0;
	es[p]=cur;
	vis[p]=0;
	while(!qu.empty()){
		qu.pop();
	}
	qu.push({p,0});
	while(!qu.empty()){
		int u=qu.top().u,w=qu.top().w;
		if(es[u]!=cur){
			es[u]=cur;
			f[u]=inf;
			vis[u]=0;
		}
		qu.pop();
		f[u]=w;
//		if(u==tv){
//			return ;
//		}
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(Edge g:e[u]){
			int v=g.v,w=g.w;
			if(es[v]!=cur){
				es[v]=cur;
				f[v]=inf;
				vis[v]=0;
			}
			if(vis[v]){
				continue;
			}
			if(f[v]>f[u]+w){
				f[v]=f[u]+w;
				qu.push({v,f[v]});
			}
		}
	}
}
void solve(){
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int u,w;
			cin>>u>>w;
			s[j].u=u;
			s[j].w=w;
			e[u].push_back({n+i,w});
			e[n+i].push_back({u,w});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>tu>>tv;
		if(tu>tv){
			swap(tu,tv);
		}
		quest[i].u=tu;
		quest[i].v=tv;
		quest[i].num=i;
//		dijkstra(tu);
//		cout<<f[tv]+a[tu]+a[tv]<<"\n";
	}
	sort(quest+1,quest+1+q,cmpu);
	for(int i=1;i<=q;i++){
		tu=quest[i].u;
		tv=quest[i].v;
		dijkstra(tu,i);
		while(i<=q&&quest[i].u==tu){
			quest[i].res=f[quest[i].v];
//			cout<<"*"<<i<<" "<<quest[i].res<<"\n";
			i++;
		}
//		for(int i=1;i<=n;i++){
//			cout<<f[i]<<" ";
//		}
//		cout<<"\n";
		i--;
	}
	sort(quest+1,quest+1+q,cmpnum);
	for(int i=1;i<=q;i++){
		cout<<quest[i].res+a[quest[i].u]+a[quest[i].v]<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
//提交subway2
//提交这个
//18:28看来已经无力回天了
//退役了退役了(悲
//mxxby是个人物(
//