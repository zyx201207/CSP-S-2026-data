#include<bits/stdc++.h>
#define ll long long
#define N 2001000 
const ll INF=1e18;
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int c,t,n,d,D,cnt[N],x[N],dis[N];bool vis[N];
struct node{ll x,dis;};queue<int>q;vector<int>v[N];
void bfs(int s){
	for(int i=1;i<=n;++i)dis[i]=INF,cnt[i]=0;
	q.push(s);cnt[s]=1,dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto g:v[u]){
			if(dis[g]==dis[u]+1)cnt[g]+=cnt[u];
			if(dis[g]>dis[u]+1){
				dis[g]=dis[u]+1;
				cnt[g]=cnt[u];q.push(g);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();ll ans=0;
		for(int i=1;i<=n;++i)x[i]=read();
		D=x[2]-x[1];bool vis=true;
		for(int i=2;i<=n&&vis;++i)if(x[i]-x[i-1]!=D)vis=false;
		if(vis){
			if(d<2*D||d>=3*D)cout<<"0\n";
			else cout<<n-4+1<<"\n";
			continue;
		}
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)
			if(x[j]-x[i]<=d)v[i].push_back(j);
		for(int i=1;i<=n;++i){
			bfs(i);
			for(int j=i+1;j<=n;++j)
				if(cnt[j]==2)++ans;	
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)v[i].clear();
	}
	return 0;
}

