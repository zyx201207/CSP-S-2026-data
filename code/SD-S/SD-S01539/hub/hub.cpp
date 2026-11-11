#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int c,t,n,k,dis[100][100],p[100],fa[100],ans=1e18;
bool vis[100],h[100][100],pp[100];
vector<int>G[100];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void hb(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	fa[fx]=fy;
}
void bfs(int x){
	vis[x]=1;
	queue<int>q;
	q.push(x);
	while(q.size()){
		int top=q.front();
		q.pop();
		for(int i:G[top]){
			if(!vis[i]){
				dis[x][i]=dis[x][top]+1;
				vis[i]=1;
				q.push(i);
			}
		}
	}
}
void dfs(int x){
	if(x==k){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=x;i++){
			for(int j=1;j<=x;j++){
				if(i==j)continue;
				if(h[p[i]][p[j]])hb(p[i],p[j]);
			}
		}
		memset(pp,0,sizeof(pp));
		int da=0;
		for(int i=1;i<=x;i++){
			if(!pp[find(p[i])]){
				pp[find(p[i])]=1;
				da++;
			}
		}
		if(da<=2){
			int pa=0;
			for(int i=1;i<=n;i++){
				int aa=1e18;
				for(int j=1;j<=x;j++){
					aa=min(aa,dis[i][p[j]]);
				}
				pa=max(pa,aa);
			}
			ans=min(ans,pa);
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[x+1]=i;
		dfs(x+1);
		p[x+1]=0;
		vis[i]=0;
	}
}
void solve() {
	ans=1e18;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
		h[x][y]=1;
		h[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	memset(vis,0,sizeof(vis));
	dfs(0);
	cout<<ans<<endl;
	memset(h,0,sizeof(h));
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++)G[i].clear();
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
