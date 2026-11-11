#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
int c,n,m,d,q;
const int N=1e3*2+500+20;
ll val[N];
int head[N],to[2*N],ne[2*N],idx;
ll wi[2*N];
int k[N];
int a[N][N],t[N][N];
void add(int u,int v,ll w){
	to[idx]=v;
	ne[idx]=head[u];
	wi[idx]=w;
	head[u]=idx++;
}
bool A=true;
ll dist[N];
bool vis[N];
void dijkstra(int s){
	memset(dist,0x3f3f,sizeof dist);
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dist[s]=0;
	q.push({dist[s],s});
	while(!q.empty()){
		auto now=q.top();q.pop();
		int a=now.first,u=now.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i!=-1;i=ne[i]){
			int v=to[i];
			if(dist[v]>a+wi[i]){
				dist[v]=a+wi[i];
				q.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(head,-1,sizeof head);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
		add((i-1)*2+1,(i-1)*2+2,val[i]);
		add((i-1)*2+2,(i-1)*2+1,val[i]);
	}
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		num+=k[i];
		if(k[i]>2)A=false;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			add((a[i][j]-1)*2+2,2*m+i,t[i][j]);
			add(2*m+i,(a[i][j]-1)*2+2,t[i][j]);
		}
	}
	if(num<=500){
		for(int i=1;i<=q;i++){
			int l,r;cin>>l>>r;
			dijkstra((l-1)*2+1);
			cout<<dist[(r-1)*2+1]<<"\n";
		}
		return 0;
	}
	if(A){
		memset(head,-1,sizeof head);
		idx=0;
		for(int i=1;i<=n;i++){
			if(k[i]==1)continue;
			add(a[i][1],a[i][2],t[i][1]+t[i][2]);
			add(a[i][2],a[i][1],t[i][1]+t[i][2]);
		}
		for(int i=1;i<=q;i++){
			int l,r;cin>>l>>r;
			dijkstra(l);
			cout<<dist[r]+val[l]+val[r]<<"\n";
		}
	}
	return 0;
}