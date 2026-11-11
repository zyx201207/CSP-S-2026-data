#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=4005;
vector<int>g[N];
int n,k,mid,dep[N],cnt;
void dfs(int u,int fa){
	int mx=0;
	for(int v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		int t=dep[v];
		if(t<0)t=-t-1;
		if(t+1>mx)mx=t+1;
		
	}
	if(mx>=mid){
		cnt++;
		dep[u]=-mid;
	}else dep[u]=mx;
}
bool check(){
	cnt=0;
	memset(dep,0,sizeof(dep));
	dfs(1,0);
	if(dep[1]>0)cnt++;
	return cnt<=k;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			
		}
		int l=0,r=n,ans=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(check()){
				ans=mid;
				r=mid-1;
				
			}
			else l=mid+1;
		}
	cout<<ans<<'\n';
		
	}
	return 0;
} 

 
