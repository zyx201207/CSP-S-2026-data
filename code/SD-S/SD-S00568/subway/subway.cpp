#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+10;
const int inf=1e18;
int c,n,m,d,q,a[N],dis[N<<1],tmp[1010][1010];
bool used[N<<1];
vector<pii> g[N<<1];
int read(){
	char ch=getchar();
	int x=0;
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch)){
		x=x*10+(int)(ch-'0');
		ch=getchar();
	}
	return x;
}
void dij(int s){
	for(int i=0;i<=n+m;i++){
		dis[i]=inf;
		used[i]=false;
	}
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[s]=0;
	q.push({dis[s],s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(used[u])
			continue;
		used[u]=true;
		for(auto e:g[u]){
			int v=e.first,w=e.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	c=read();
	m=read();
	n=read();
	d=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++){
		int k;
		k=read();
		for(int j=1;j<=k;j++){
			int u,t;
			u=read();
			t=read();
			g[n+i].push_back({u,t});
			g[u].push_back({n+i,t});
		}
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++)
				tmp[i][j]=dis[j];
		}
		while(q--){
			int x,y;
			x=read();
			y=read();
			cout<<tmp[x][y]+a[x]+a[y]<<"\n";
		}
		return 0;
	}
	while(q--){
		int x,y;
		x=read();
		y=read();
		int ans=0;
		ans+=a[x]+a[y];
		dij(x);
		ans+=dis[y];
		cout<<ans<<"\n";	
	}
	return 0;
}
