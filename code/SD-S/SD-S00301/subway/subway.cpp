#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 600005
int c,n,m,dii,Q;
int a[N];
int d[N];
int head[N];
int w[N];
struct Edge{
	int f;
	int t;
	int v;
	int nxt;
}edge[N*5];
int ttt=0;
void add_edge(int f,int t,int v){
	ttt++;
	edge[ttt].f=f;
	edge[ttt].t=t;
	edge[ttt].v=v;
	edge[ttt].nxt=head[f];
	head[f]=ttt;
	return ;
}
struct Dot{
	int id;
	int fr;
	bool operator >(const Dot & a)const{
		return fr<a.fr;
	}
	bool operator <(const Dot & a)const{
		return fr>a.fr;
	}
};
priority_queue<Dot>q;
bool vis[N];
int dis[N];
//int cnt=0;
void dij(int st){
	for(int i=1;i<=n+m;i++){
//		cnt++;
		dis[i]=1e18;
		vis[i]=0;
	}
	Dot k;
	k.id=st;
	k.fr=0;
	dis[st]=0;
	q.push(k);
	while(!q.empty()){
		Dot kl=q.top();
		q.pop();
		int u=kl.id;
		int f=kl.fr;
		if(f!=dis[u]||vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
//			cnt++;
			int t=edge[i].t;
			int v=edge[i].v;
			if(dis[t]<=f+v){
				continue;
			}
			dis[t]=f+v;
			Dot kk;
			kk.id=t;
			kk.fr=dis[t];
			q.push(kk);
		}
	}
	return ;
}
struct Query{
	int r;
	int id;
};
vector<Query> qu[N];
int ra[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	memset(dis,0x3f,sizeof(dis));
	cin>>c>>m>>n>>dii>>Q;
//	cnt++;
	for(int i=1;i<=n;i++){
//		cnt++;
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int k;
//		cnt++;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>d[j];
//			cnt+=2;
			add_edge(a[j],n+i,d[j]);
			add_edge(n+i,a[j],d[j]);
		}
	}
	for(int i=1;i<=Q;i++){
		int l,r;
		cin>>l>>r;
		Query p;
		p.r=r;
		p.id=i;
		qu[l].push_back(p);
	}
	for(int i=1;i<=n;i++){
		if(qu[i].size()==0){
			continue;
		}
		dij(i);
		
		for(int j=0;j<qu[i].size();j++){
			int id=qu[i][j].id;
			int r=qu[i][j].r;
			ra[id]=dis[r]+w[i]+w[r];
		}
	}
	for(int i=1;i<=Q;i++){
		cout<<ra[i]<<'\n';
	}
	return 0;
}
