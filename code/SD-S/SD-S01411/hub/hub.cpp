#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,k;
int a,b;
int f[N];
int find(int x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
bool vis[N];
vector<int> v[N];
int s[N];
int ans;
int d[1010][1010];
void work(){
	int cnt=0,tmp=k;
	for(int i=1;i<=n;i++){
		f[i]=i;
		if(vis[i]) s[++cnt]=i;
	}
	for(int i=1;i<=k;i++){
		for(int j:v[s[i]]){
			if(vis[j]){
				int fi=find(s[i]);
				int fj=find(j);
				if(fi!=fj){
					f[fi]=fj;
					--tmp;
				}
			}
		}
	}
	if(tmp>2) return;
	int mx=0;
	for(int i=1;i<=n;i++){
		int mi=1e9;
		for(int j=1;j<=k;j++){
			mi=min(mi,d[i][s[j]]);
		}
		mx=max(mx,mi);
	}
	ans=min(ans,mx);
}
void dfs(int now,int cnt){
	if(cnt==k){
		work();
		return;
	}
	if(now==n+1) return;
	vis[now]=true;
	dfs(now+1,cnt+1);
	vis[now]=false;
	dfs(now+1,cnt);
}
void dfs0(int rt,int x,int fa,int deep){
	d[rt][x]=deep;
	for(int i:v[x]){
		if(i!=fa){
			dfs0(rt,i,x,deep+1);
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear(),vis[i]=false;
		}
		for(int i=1;i<n;i++){
			cin>>a>>b;
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		for(int i=1;i<=n;i++){
			dfs0(i,i,0,0);
		}
		ans=0x3f3f3f3f3f3f3f3f;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
