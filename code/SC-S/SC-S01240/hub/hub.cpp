#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,inf=1e9;
int c,t,n,k,cnt,h[N],dep[N],mx[N],fa[N][20];
bool tag[N];
struct edge{
	int v,nx;
}e[N*2];
void add(int u,int v){
	e[++cnt]={v,h[u]};
	h[u]=cnt;
}
void dfs(int u){
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;i<20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=h[u];i;i=e[i].nx){
		if(e[i].v==fa[u][0]){
			continue;
		}
		fa[e[i].v][0]=u;
		dfs(e[i].v);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=19;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int dis(int x,int y){
	int u=lca(x,y);
	return dep[x]+dep[y]-2*dep[u];
}
bool check(int s){
	for(int x=1;x<=n;x++){
		for(int y=x+1;y<=n;y++){
			int flag=1;
			for(int i=1;i<=n;i++){
				if(dis(x,i)>s&&dis(y,i)>s){
					flag=0;
				}
			}
			if(flag){
				return 1;
			}
		}
	}
	return 0;
}
int count(int u){
	int sum=tag[u];
	for(int i=h[u];i;i=e[i].nx){
		if(e[i].v==fa[u][0]){
			continue;
		}
		int x=count(e[i].v);
		if(tag[u]&&tag[e[i].v]){
			sum+=x-1;
		}
		else{
			sum+=x;
		}
	}
	return sum;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			h[i]=0;
		}
		cnt=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs(1);
		if(k==2){
			int l=0,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(check(mid)){
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			cout<<l<<"\n";	
		}
		else{
			int ans=inf;
			for(int i=0;i<(1<<n);i++){
				vector<int>v;
				for(int j=1;j<=n;j++){
					if(i&(1<<j-1)){
						v.push_back(j);
						tag[j]=1;
					}
					else{
						tag[j]=0;
					}
				}
				if(v.size()!=k){
					continue;
				}
				if(count(1)>2){
					continue;
				}
				int mx=0;
				for(int j=1;j<=n;j++){
					int mi=inf;
					for(int x=0;x<k;x++){
						mi=min(mi,dis(j,v[x]));
					}
					mx=max(mx,mi);
				}
				ans=min(ans,mx);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}