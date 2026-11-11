#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,vis[N],dis[N][N],t,ans,k;
vector<int>g[N];
void dfs1(int id,int x,int last,int d){
	dis[id][x]=d;
	for(int v:g[x])if(v!=last){
		dfs1(id,v,x,d+1);
	}
}
void dfs2(int id,int x,int last){
	vis[x]=1;
	for(int v:g[x])if(v!=last&&((id>>(v-1))&1))dfs2(id,v,x);
}
bool check(int x){
	if(__builtin_popcount(x)!=k)return 1;
	for(int i=1;i<=n;i++)vis[i]=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(((x>>i)&1)&&!vis[i+1])dfs2(x,i+1,0),cnt++;
		if(cnt>2)return 1;
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>t;
	while(t--){
		cin>>n>>k,ans=n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,a,b;i<n;i++)cin>>a>>b,g[a].push_back(b),g[b].push_back(a);
		for(int i=1;i<=n;i++)dfs1(i,i,0,0);
		for(int bit=0;bit<(1<<n);bit++){
			if(check(bit))continue;
			int s=0;
			for(int i=1;i<=n;i++){
				int di=n;
				for(int j=0;j<n;j++){
					if((bit>>j)&1){
						di=min(di,dis[i][j+1]);
					}
				}
				s=max(s,di);
			}
			ans=min(ans,s);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
