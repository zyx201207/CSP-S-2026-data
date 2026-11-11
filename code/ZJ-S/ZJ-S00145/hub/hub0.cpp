namespace c7_11_12{
	using namespace IO;
	const int MAXN=100010;
	int n,k;
	int U[MAXN],V[MAXN],G[2*MAXN],deg[MAXN],Du[MAXN],dep[MAXN];
	int que[MAXN],hed,til,dis[MAXN];
	void DFS(int u,int fa){
		dep[u]=dep[fa]+1;
		for(int j=deg[u]+1;j<=deg[u+1];j++){
			int v=G[j];
			if(v!=fa)DFS(v,u);
		}
	}
	bool check(int len){
		hed=til=0;
		memset(dis,-1,sizeof(int)*(n+5));memset(Du,-1,sizeof(int)*(n+5));
		for(int i=1;i<n;i++)Du[U[i]]++,Du[V[i]]++;
		for(int i=1;i<=n;i++)if(Du[i]==0){
			dis[i]=0;
			que[++til]=i;
		}
		int cnt=0;
		while(hed!=til){
			int u=que[++hed];
			if(dis[u]==len){cnt++;continue;}
			for(int j=deg[u]+1;j<=deg[u+1];j++){
				int v=G[j];
				if(dis[v]==-1){
					dis[v]=dis[u]+1;
					que[++til]=v;
				}
			}
		}
		return cnt<=2;
	}
	void solve(){
		n=readint(),k=readint();
		memset(deg,0,sizeof(int)*(n+5));
		for(int i=1;i<n;i++)U[i]=readint(),V[i]=readint(),deg[U[i]]++,deg[V[i]]++;
		for(int i=1;i<=n;i++)deg[i+1]+=deg[i];
		for(int i=1;i<n;i++)G[deg[U[i]]--]=V[i],G[deg[V[i]]--]=U[i];
		dep[0]=-1;
		DFS(1,0);
		int rt=1;
		for(int i=2;i<=n;i++)if(dep[i]>dep[rt])rt=i;
		DFS(rt,0);
		int L=dep[1],R=n,ans=n;
		for(int i=2;i<=n;i++)if(dep[i]>L)L=dep[i];
		L=(L+1)/4;
		while(L<=R){
			int mid=L+R>>1;
			if(check(mid))ans=mid,R=mid-1;
			else L=mid+1;
		}
		cout<<ans<<'\n';
	}
	void Main(){
		int T=readint();
		while(T--)solve();
	}
}
