//SN-S00283 Aapwp gxyz
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int id,T,n,a[maxn],d;
struct edge{
	int to,nxt;
}e[maxn<<1];
int head[maxn],edgenum;
void add_edge(int u,int v){
	e[++edgenum].nxt=head[u];
	e[edgenum].to=v;
	head[u]=edgenum;
}

bool vis[maxn];
int dis[maxn];
struct node{
	int pos,dis;
	bool operator < (const node &x)const{
		return x.dis<dis;	
	}
};
priority_queue<node> q;
vector<int> pre[maxn];
void dij(int x){
	for(int i=1;i<=n;i++){
		dis[i]=2e9,vis[i]=0;
		pre[i].clear();
	}
	dis[x]=0;
	q.push((node){x,0});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				pre[v].clear(),pre[v].push_back(u);
				if(!vis[v]) q.push((node){v,dis[v]});
			}
			else if(dis[v]==dis[u]+1)
				pre[v].push_back(u); 
		}	
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<":";
//		for(auto x:pre[i]) cout<<x<<" ";
//		cout<<endl;
//	}
//	cout<<endl;
}

bool check(int x,int y){
	int fl=0;
	for(int i=y;i!=x;i=pre[i][0]){
		if(pre[i].size()>2 || pre[i].size()==0) return 0;
		if(pre[i].size()==2) fl++;
	}
	if(fl==1) return 1;
	return 0;
}

void clean(){
	edgenum=0;
	for(int i=1;i<=n;i++) head[i]=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>id>>T;
	if(id==13 || id==14){
		
	}
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d) add_edge(i,j),add_edge(j,i);
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		clean();
	}
	
}
/*
0 1
10 2
1 2 3 4 5 6 7 8 9 10
*/
