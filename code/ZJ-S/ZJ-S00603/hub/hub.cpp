#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,t,n,k,x,y,v[N][N],dis[N][N],f[N],fa[N],ans=N;
pair<int,int> a[N];
priority_queue<pair<int,int>,vector<pair<int,int> >
,greater<pair<int,int> > > q;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dij(int x){
	for(int i=1;i<=n;i++) dis[x][i]=N;
	dis[x][x]=0;
	q.push({0,x});
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(dis[x][u]!=d) continue;
		for(int i=1;i<=n;i++){
			if(v[i][u]==0) continue;
			int fi=i,se=1;
			if(d+se<dis[x][fi]){
				dis[x][fi]=d+se;
				q.push({dis[x][fi],fi});
			}
		}
	}
}
int r(){
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(f[i] && f[j] && v[i][j]==1){
				int fx=find(i),fy=find(j);
				if(fx!=fy) fa[fx]=fy;
			}
		}
	}
	set<int> st;
	for(int i=1;i<=n;++i){
		if(f[i]==1) st.insert(fa[i]);
	}
	if(st.size()!=2) return N;
	int u=0;
	for(int i=1;i<=n;++i){
		int w=N;
		for(int j=1;j<=n;++j){
			if(f[j]) w=min(w,dis[i][j]);
		}
		u=max(u,w);
	}
	return u;
}
void dfs(int t,int su){
	if(su>k) return;
	if(t==n+1){
		if(su==k) ans=min(ans,r());
		return;
	}
	f[t]=0;
	dfs(t+1,su);
	f[t]=1;
	dfs(t+1,su+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=N;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				v[i][j]=0;
			}
		}
		for(int i=1;i<n;++i){
			cin>>x>>y;
			v[x][y]=1; v[y][x]=1;
		} 
		for(int i=1;i<=n;++i){
			dij(i);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}

