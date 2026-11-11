#include<bits/stdc++.h>
using namespace std;
vector<int>vec[1000005];
int dep[1000005];
int fat[1000005];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	fat[x]=fa;
	for(int v:vec[x]){
		if(v==fa)continue;
		dfs(v,x);
	}
}
int n,k;
bool alive[1000005];
void duel(int x,int dis,int fa){
	alive[x]=0;
	if(dis==0)return ;
	for(int v:vec[x]){
		if(v==fa)continue;
		duel(v,dis-1,x);
	}
}
bool check(int x){
	for(int i=1;i<=n;i++)alive[i]=1;
	int Maxid=0;
	for(int i=1;i<=n;i++){
		if(dep[i]>dep[Maxid])Maxid=i;
	}
	int u=Maxid;
	for(int i=1;i<=x;i++){
		u=fat[u];
		if(u==0)return 1;
	}
	duel(u,x,0);
	
	Maxid=0;
	for(int i=1;i<=n;i++){
		if(alive[i] && dep[i]>dep[Maxid])Maxid=i;
	}
	if(Maxid==0)return 1;
	u=Maxid;
	for(int i=1;i<=x;i++){
		u=fat[u];
		if(u==0)return 1;
	}
	duel(u,x,0);
	
	for(int i=1;i<=n;i++){
		if(alive[i]==1)return 0;
	}
	return 1;
}

vector<int>ch;
bool vis[15];
bool choose[15];
int dis[15];
bool ttt=0;
void paint(int x){
	vis[x]=1;
	for(int v:vec[x]){
		if(choose[v] && !vis[v]){
			paint(v);
		}
	}
}
void ggg(int x,int d,int fa){
	dis[x]=min(dis[x],d);
	for(int v:vec[x]){
		if(v!=fa)ggg(v,d+1,x);
	}
}
int Ans=0x3f3f3f3f;
void work(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	int tmp=0;
	for(int v:ch){
		if(!vis[v])paint(v),tmp++;
	}
	if(tmp>2)return ;
	for(int v:ch){
		ggg(v,0,0);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dis[i]);
	Ans=min(Ans,ans);
}
void solve(int x,int num){
	if(x==n+1 ){
		if(num==k)work();
		return ;
	}
	solve(x+1,num);
	ch.push_back(x);
	choose[x]=1;
	solve(x+1,num+1);
	choose[x]=0;
	ch.pop_back();
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;cin>>c>>t;
	while(t--){
		memset(fat,0,sizeof(fat));
		memset(dep,0,sizeof(dep));
		cin>>n>>k;
		for(int i=1;i<=n;i++)vec[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		dfs(1,0);
		if(k==2){
			int l=0,r=n,ans=-1;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid)){
					r=mid-1,ans=mid;
				}
				else l=mid+1;
			}
			cout<<ans<<'\n';
		}
		else {
			Ans=0x3f3f3f3f;
			solve(1,0);
			cout<<Ans<<'\n';
		}
	}
}
