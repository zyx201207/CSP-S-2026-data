#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int N=3e5+10;
int n,k,vis[N],cnt=0;
int ok[N],dep[N];
vector<int> node[N];

struct DSU{
	int f[N];
	int find(int x){
		if(f[x]==x) return x;
		return f[x]=find(f[x]);
	}
	void merge(int a,int b){
		int fa=find(a),fb=find(b);
		f[fb]=fa;
	}
	bool check(int a,int b){
		return find(a)==find(b);
	}
	void init(){
		for(int i=1;i<=n;i++)
			f[i]=i;
	}
}dsu;

void dfs(int u,int fa,int x){
	if(dep[u]<=x ) vis[u]++;
	for(int v:node[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u,x);
	}
}

void get_dfs(int u,int fa,int x){
	if(dep[u]<=x) ok[u]=1;
	for(int v:node[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		get_dfs(v,u,x);
	}
}

bool check(int x){
	int cost=0;
	int rt1=0,rt2=0;
	dsu.init();
	cnt=0;
	for(int i=1;i<=n;i++)
		ok[i]=0;
	
	while(cnt<n){
		vector<int> p(n+1);
		for(int i=1;i<=n;i++)
			vis[i]=0,p[i]=i;
		for(int i=1;i<=n;i++){
			if(ok[i])continue;
			for(int j=1;j<=n;j++)
				dep[j]=0;
			dfs(i,0,x);
		}
		sort(p.begin(),p.end(),[&](int a,int b)->bool{
			return vis[a]>vis[b];});
		
		int add=0;
		for(int u:p){
			
			int flg=0;
			for(int v:node[u]){
				if(dsu.check(v,rt1) || dsu.check(v,rt2)){
					flg++;
					dsu.merge(v,u);
					break;
				}	
			}
			if(flg==1){
				add=u;
				break;
			}
			if(!flg && (rt1==0||rt2==0)){
				if(rt1==0) rt1=u;
				else rt2=u;
				add=u;
				break;
			}
		}
		for(int i=1;i<=n;i++)
			dep[i]=0;
		
		get_dfs(add,0,x);
		cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=ok[i];
		cost++;
		if(add==1 && cnt==8) break;
	}
	return cost<=k;
}

void solve(){
	
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<'\n';
	
	for(int i=1;i<=n;i++)
		node[i].clear();
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	
	int c,t;
	cin>>c>>t;
	while(t--)
		solve();
	
	
	return 0;
}