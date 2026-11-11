#include<bits/stdc++.h>
using namespace std;
#include<queue>
#define int long long
#define fs first
#define sc second
const int N=5e5+50;
int c,n,m,d,q;
int w[N];
struct pc{
	int head[N*2+1000],next[N*2+1000];
	int go[N*2+1000],v[N*2+1000],l=0;
	void add(int x,int y,int z){
		next[++l]=head[x];
		head[x]=l;
		go[l]=y;
		v[l]=z;
	}
}p;
int wt[510][510];
int f[510][510];
int vs[510][510];
void dfs(int x){
	priority_queue<pair<int,int>>pq;	
	pq.push({0,x});
	while(pq.size()){
		while(pq.size()&&vs[x][pq.top().sc])pq.pop();
		if(pq.size()==0)return ;
		pair<int,int>t;
		t=pq.top();
		pq.pop();
		vs[x][t.sc]=1;
		for(int i=1;i<=n;i++){
			if(f[x][i]>f[x][t.sc]+wt[t.sc][i]){
				f[x][i]=f[x][t.sc]+wt[t.sc][i];
				pq.push({-f[x][i],i});
			}
		}
	}
}
void sol(){
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >>k;
		while(k--){
			int kkk,ttt;
			cin >>kkk>>ttt;
			p.add(kkk,m+i,ttt);
			p.add(m+i,kkk,ttt);
		}	
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)f[i][j]=wt[i][j]=0;
			else f[i][j]=wt[i][j]=1e16+20;
	for(int u=1;u<=n;u++){
		for(int i=p.head[u+m];i;i=p.next[i]){
			int v=p.go[i];
			for(int j=p.head[v];j;j=p.next[j]){
				int lt=p.go[j];
				wt[u][lt-m]=min(wt[u][lt-m],p.v[i]+p.v[j]);
			}
		}
	}
	for(int k=1;k<=n;k++)dfs(k);
	while(q--){
		int x,y,ans=1e16+20;
		cin >>x>>y;
		for(int i=p.head[x];i;i=p.next[i])
		for(int j=p.head[y];j;j=p.next[j])
			ans=min(ans,w[x]+w[y]+f[p.go[i]-m][p.go[j]-m]
			+p.v[i]+p.v[j]);
		cout<<ans<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t=1;
//	cin >>t;
	while(t--)
		sol();
	return 0;
}
