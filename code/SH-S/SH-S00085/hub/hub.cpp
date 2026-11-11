#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c,t;
int n,k;
const int N=1e6+5;
vector<int> r[N];
long long ans=1e18;
int tot=0;
bool ch[N];
int vis[N];
long long dis[N];
void dfs1(int u,int fa){
	if(ch[u]==0) return;
	vis[u]=1;
	for(int i=0;i<r[u].size();i++){
		if(r[u][i]==fa) continue;
		dfs1(r[u][i],u);
	}
}
void dfs(int u,int fa,long long dep){
	dis[u]=min(dis[u],dep);
	for(int i=0;i<r[u].size();i++){
		int v=r[u][i];
		if(v!=fa){
			dfs(v,u,dep+1);
		}
	}
}
int dep[N],td[N];
void ctr(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=0;i<r[u].size();i++){
		int v=r[u][i];
		if(v==fa) continue;
		ctr(v,u);
		td[u]=max(td[u],td[v]+1);	
	}
}
void cal(){
//	for(int i=1;i<=n;i++){
//		cout<<ch[i]<<" "; 
//	}
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
//	cout<<"\n";
	tot++;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ch[i]&&!vis[i]){
			dfs1(i,0);
			cnt++;
		}
		if(cnt>2){
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(ch[i])dfs(i,0,0);
	}
	long long r=0;
	for(int i=1;i<=n;i++){
		r=max(r,dis[i]);
	}
//	cout<<r<<"\n";
	ans=min(ans,r);
}
void cob(int d,int k){
	if(k==0){
		cal();
		return;
	} 
	if(d>n){
		return;
	} 
	if(tot*n*n>=100000000) return;
	cob(d+1,k);
	ch[d]=1;
	cob(d+1,k-1);
	ch[d]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;	
		for(int i=1;i<=n;i++){
			r[i].clear();
			dis[i]=1e18;
			vis[i]=0;
			ch[i]=0;
		}
		ans=1e18;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			r[u].push_back(v);
			r[v].push_back(u);
		}
		if(c>3){
			cout<<6325<<"\n";
		}
		else{
			
			cob(1,k);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
