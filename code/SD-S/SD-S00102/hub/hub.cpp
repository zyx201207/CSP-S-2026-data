#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=186;
int C,T,n,k;
struct node{
	int from,to;
}way[N];
vector<int> a[N];
int st[N][20],dep[N],r[N],dist[N][N];
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((x>>i)&1) cnt++;
	}
	if(cnt!=k) return 0;
	cnt=0;
	for(int i=1;i<n;i++){
		int u=way[i].from;
		int v=way[i].to;
		if(((x>>u)&1)&&((x>>v)&1))cnt++;
	}
	if(cnt<k-2) return 0;
	return 1;
}
void dfs(int u,int fa){
	st[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=15;i++){
		st[u][i]=st[st[u][i-1]][i-1];
	}
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	return;
}
int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	int dif=dep[u]-dep[v];
	for(int i=15;i>=0;i--){
		if((dif>>i)&1){
			u=st[u][i];
		}
	}
	if(u==v) return u;
	for(int i=15;i>=0;i--){
		if(st[u][i]!=st[v][i]){
			u=st[u][i];
			v=st[v][i];
		}
	}
	return st[u][0];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			r[i]=0x3f3f3f3f;
			a[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
			way[i].from=u;
			way[i].to=v;
		}
		dfs(1,0);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dist[i][j]=dist[j][i]=dep[i]+dep[j]-2*dep[lca(i,j)];
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=2;i<(1<<(n+1));i+=2){
			if(!check(i)) continue;
			for(int j=1;j<=n;j++){
				r[j]=0x3f3f3f3f;
			}
			for(int j=1;j<=n;j++){
				if((i>>j)&1){
					for(int k=1;k<=n;k++){
						r[k]=min(r[k],dist[j][k]);
					}
				}
			}
			int ans1=0;
			for(int j=1;j<=n;j++){
				ans1=max(ans1,r[j]);
			}
			ans=min(ans,ans1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
