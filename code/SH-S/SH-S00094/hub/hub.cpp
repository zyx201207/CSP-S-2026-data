#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,u,v,dp[20][20],x,f[1000010],ans,o,p,s,w;
vector<int> g[1000010];
bool vs[1000010];
queue<int> q;
inline int fd(int x){
	if(x==f[x])
		return x;
	return f[x]=fd(f[x]);
}
inline void cb(int x,int y){
	x=fd(x);
	y=fd(y);
	if(x!=y)
		f[x]=y;
}
inline void ck(){
	for(int i=1;i<=n;++i)
		f[i]=i;
	for(int i=1;i<=n;++i){
		if(vs[i]){
			for(int j:g[i])
				if(vs[j])
					cb(i,j);
		}
	}
	o=0;
	p=0;
	for(int i=1;i<=n;++i)
		if(vs[i]){
			if(fd(i)!=o&&fd(i)!=p){
				if(o==0)
					o=fd(i);
				else if(p==0)
					p=fd(i);
				else
					return;
			}
		}
	s=0;
	for(int i=1;i<=n;++i){
		if(!vs[i]){
			w=1e9;
			for(int j=1;j<=n;++j){
				if(vs[j]){
					w=min(w,dp[i][j]);
				}
			}
			s=max(s,w);
		}
	}
	ans=min(s,ans);
	return;
}
inline void dfs(int x,int y){
	if(x>n){
		if(y==k)
			ck();
		return;
	}
	vs[x]=1;
	dfs(x+1,y+1);
	vs[x]=0;
	dfs(x+1,y);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			g[i].clear();
			vs[i]=0;
		}
		for(int i=1;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)
				vs[j]=0;
			q.push(i);
			vs[i]=1;
			dp[i][i]=0;
			while(!q.empty()){
				x=q.front();
				q.pop();
				for(int v:g[x]){
					if(vs[v])
						continue;
					dp[i][v]=dp[i][x]+1;
					vs[v]=1;
					q.push(v);
				}
			}
		}
		ans=1e9;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
