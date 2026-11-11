#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5+10;
const int N = 550;
const int INF = 0x7fffffffffffffff;

int Cas,n,m,D,Q;
int w[M],k[N];
int ans;
int vis[M];

struct node1{
	int is;
	int tim;
};
vector<node1> t[M];
vector<int> lin[N];

int head[M],ce=1;
struct Edge{
	int to,nxt,w;
}edge[M<<1];

void adde(int from,int to,int w){
	edge[++ce].to=to;
	edge[ce].w=w;
	edge[ce].nxt=head[from];
	head[from]=ce;
}

int find(int x,int is){
	for(int i=0;i<t[x].size();++i){
		if(t[x][i].is==is) return t[x][i].tim;
	}
}

void dfs(int x,int ed,int lis,int cnt){
	if(x==ed){
		ans=min(ans,cnt+find(ed,lis));
		return;
	}
	if(cnt>=ans) return;
	for(int i=head[x];i>1;i=edge[i].nxt){
		int y=edge[i].to;
		int w=edge[i].w;
		if(vis[y]) continue;
		if(w==lis) continue;
		vis[y]=1;
		dfs(y,ed,w,cnt+find(x,lis)+find(x,w));
		vis[y]=0;
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>Cas>>n>>m>>D>>Q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int x,tt;
			cin>>x>>tt;
			node1 tmp;
			tmp.is=i;
			tmp.tim=tt;
			t[x].push_back(tmp);
			lin[i].push_back(x);
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<t[i].size();++j){
			int p=t[i][j].is;
			for(int k=0;k<lin[p].size();++k){
				if(lin[p][k]!=i){
					adde(i,lin[p][k],p);
					adde(lin[p][k],i,p);
				}
			}
		}
	}
	for(int i=1;i<=Q;++i){
		int x,y;
		cin>>x>>y;
		ans=INF;
		for(int j=1;j<=m;++j) vis[j]=0;
		vis[x]=1;
		dfs(x,y,0,0);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
