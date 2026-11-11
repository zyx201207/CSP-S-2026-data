#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=20;

template<typename T> void chkmax(T &x,T y) {if(y>x) x=y;}
template<typename T> void chkmin(T &x,T y) {if(y<x) x=y;}


int n,k,ans=1e9;
int dis[N][N];
bool vis[N],w[N][N];
//vector<int>g[N];

struct dus{
	int f[N];
	
	void init(){
		for(int i=1;i<=n;i++) f[i]=i;
	}
	
	int find(int x){
		if(f[x]==x) return x;
		else return f[x]=find(f[x]); 
	}
	
	void merge(int u,int v){
		u=find(u);
		v=find(v);
		f[v]=u;
	}
	
}d; 

bool check(){
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) cnt++; 
	}
	
	if(cnt!=k) return 0;
	
	d.init();
	
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(int j=i+1;j<=n;j++){
			if(!vis[j]) continue;
			if(w[i][j]){
				if(d.find(i)!=d.find(j)) d.merge(i,j);
			} 
		}
	}
	
	set<int>st; 
	
	for(int i=1;i<=n;i++){
		if(vis[i]) st.insert(d.find(i)); 
	}
	return st.size()<=2;
}


int calc(){
	
	int res=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e9; 
	}
	
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=1;j<=n;j++){
			if(w[i][j]==0||w[j][i]==0) continue;
			dis[i][j]=dis[j][i]=1;
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				chkmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		int minn=1e9;
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			chkmin(minn,dis[i][j]);
		}
		chkmax(res,minn);
	}
	return res;
} 


void dfs(int x){
	if(x==n+1){
		if(check()){
//			for(int i=1;i<=n;i++){
//				if(vis[i]) cout<<i<<' ';
//			}
//			cout<<calc()<<'\n';
//			cout<<'\n';
			chkmin(ans,calc());
		}
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}

void solve(){
	
	ans=1e9;
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		vis[i]=0;
		for(int j=1;j<=n;j++){
			w[i][j]=0;
		}
	}
	
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		w[u][v]=1;
		w[v][u]=1;
	}
	
	vis[1]=1;
	vis[3]=1;
	
//	cout<<calc()<<'\n';
	
	dfs(1);
	
	cout<<ans<<'\n';
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	
	return 0;
}

