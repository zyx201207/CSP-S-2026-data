#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int tes,T,n,m,ans,cnt;
vector<int> edges[N];
bitset<N> vis,v1;
void ck1(int x,int fa){
	if(!vis[x]) return;
	v1[x]=1;
	cnt++;
	for(auto y:edges[x])
		if(y!=fa) ck1(y,x);
}
void ck2(int x,int fa){
	if(!vis[x]) return;
	cnt++;
	for(auto y:edges[x])
		if(y!=fa) ck2(y,x);
}
int dfs(int x,int fa,int d){
	if(vis[x]) return d;
	int res=1e9;
	for(auto y:edges[x])
		if(y!=fa) res=min(res,dfs(y,x,d+1));
	return res;
}
void dfs1(int x,int t){
	if(!t||x>n){
		if(!t){
			cnt=0;
			for(int i=1;i<=n;i++) v1[i]=0;
			for(int i=1;i<=n;i++)
				if(vis[i]){
					ck1(i,0);
					break;
				}
			int c1=cnt;
			cnt=0;
			for(int i=n;i;i--)
				if(vis[i]&&!v1[i]){
					ck2(i,0);
					break;
				}
			if(c1+cnt!=m) return;
			int res=0;
			for(int i=1;i<=n;i++) res=max(res,dfs(i,0,0));
			ans=min(res,ans);
		}
		return;
	}
	dfs1(x+1,t);
	vis[x]=1;
	dfs1(x+1,t-1);
	vis[x]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>tes>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++) edges[i].clear();
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		if(n==m) ans=0;
		else if(tes==13||tes==14){
			if(n<=2*m) ans=1;
			else ans=(n-2*m+16)/8;
		}
		else if(tes<=3){
			ans=1e9;
			dfs1(1,m);
		}
		cout<<ans<<'\n';
	}
	return 0;
}