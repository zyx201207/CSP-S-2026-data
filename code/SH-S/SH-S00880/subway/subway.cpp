#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=510;    //地铁线路数 
const int M=5e5+10; //点数 
const int Q=1e5+10;
const ll INF=4e18;
int c,n,m,d,q,s;
ll w[M];
int k[N];
struct edge{
	int v;
	ll w;
};
vector<edge> e[M];
struct qlist{
	int x,y,id;
	bool operator < (const qlist &other){
		if(x != other.x) return x<other.x;
		else return y<other.y;
	}
};
vector<qlist> q_list;
ll ans[Q];

struct node{
	int u;
	ll dis;
	bool operator < (const node &other) const {
		return dis > other.dis;
	}
};
priority_queue<node> pq;
bool vst[M];
ll dis[M];


ll read(){
	ll k=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

void write(ll x){
	if(x<0) putchar('-');
	else if(x<10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

void dijkstra(int s){
	fill(dis+1,dis+m+1,INF);
	fill(vst+1,vst+m+1,0);
	dis[s]=0;
	pq.push((node){s, dis[s]});
	while(!pq.empty()){
		int u=pq.top().u; pq.pop();
		if(vst[u]) continue;
		vst[u]=1;
		for(int i=0;i<(int)e[u].size();i++){
			int v=e[u][i].v; ll w=e[u][i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push((node){v, dis[v]});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	c=read(), n=read(), m=read(), d=read(), q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		vector<int> a;
		vector<ll> t;
		a.resize(k[i]+1);
		t.resize(k[i]+1);
		for(int j=1; j<=k[i]; j++){
			a[j] = read(), t[j] = read();
		}
		for(int l=1;l<=k[i];l++)
		for(int r=l+1;r<=k[i];r++){
			e[a[l]].push_back((edge){a[r], t[l]+t[r]});
			e[a[r]].push_back((edge){a[l], t[l]+t[r]});
		}
	}
	for(int i=1;i<=q;i++){
		int x=read(), y=read();
		q_list.push_back((qlist){x,y,i});
	}
	sort(q_list.begin(), q_list.end());
	
	int nx=0;
	for(qlist q1:q_list ){
		if(q1.x!=nx){
			nx=q1.x;
			dijkstra(nx);
		}
		ans[q1.id] = dis[q1.y] + w[nx] + w[q1.y];
	}
	for(int i=1;i<=q;i++) write(ans[i]), putchar('\n');
	
	return 0;
}
