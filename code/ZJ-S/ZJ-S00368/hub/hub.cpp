#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
#define f1 first
#define s2 second
const int N=1e6+10;
int n,k,ans=1e18;
int fa[N],d[N],answer;
vector<int> a,G[N];
bool f=false;
bool vis[N],h[N];
int find(int x){
	if(fa[x]==x) return x;
	else fa[x]=find(fa[x]);
}
void init(){for(int i=1;i<=n;i++) fa[i]=i;}
void dist(int i,int j,int far,int step){
	for(auto v:G[i]){
		if(v==far) continue;
		if(v==j){
			answer=step;
			f=true;
			return ;
		}
		else dist(v,j,i,step+1);
		if(f) return ;
	}
}
void dfs(int w,int sum){
	if(sum>k) return ;
	if(w==n+1){
		if(sum!=k) return ;
		a.clear();
		init();
		for(int i=1;i<=n;i++){
			if(vis[i]) a.push_back(i);
		}
		int len=a.size();
		for(int i=0;i<len;i++){
			for(auto v:G[a[i]]){
				if(vis[v]){
					int fx=find(a[i]),fy=find(v);
					if(fx!=fy) fa[fx]=fy;
				}
			}
		}
		int cnt=0;
		memset(h,false,sizeof h );
		for(int i=0;i<len;i++){
			if(h[fa[a[i]]]==false) h[fa[a[i]]]=true,cnt++;
		}
		if(cnt>2) return ;
		int anss=-1e18;
		memset(d,0x3f,sizeof d );
		for(int i=1;i<=n;i++){
			if(vis[i]) d[i]=0;
			for(int j=0;j<len;j++){	
				answer=1e18;
				dist(a[i],a[j],0,0);
				d[i]=min(d[i],answer);
			}
			anss=max(anss,d[i]);
		}
		ans=min(ans,anss);
		return ;
	}
	else{
		vis[w]=true;
		dfs(w+1,sum+1);
		vis[w]=false;
		dfs(w+1,sum);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v),G[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}