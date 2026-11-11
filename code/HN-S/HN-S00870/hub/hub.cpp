#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,dp[1005],fa[1005],fa1[1005],maxs,mins=1e18;
vector<int> arr[1005];
struct S{
	int a,b;
}tu[1005];
bool f[1005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int find1(int x){
	if(fa1[x]==x){
		return x;
	}
	return fa1[x]=find1(fa1[x]);
}
void dfs1(int x,int fa){
	dp[x]=dp[fa]+1;
	if(dp[x]>maxs){
		maxs=dp[x];
	}
	int o=arr[x].size();
	for(int i=0;i<o;i++){
		int v=arr[x][i];
		if(v==fa || f[v]){
			continue;
		}
		dfs1(v,x);
	}
}
void dfs(int x){
	if(x==m+1){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			fa1[i]=i;
		}
		for(int i=1;i<n;i++){
			if(f[tu[i].a] && f[tu[i].b]){
				int x=find(tu[i].a),y=find(tu[i].b);
				if(x!=y){
					fa[x]=y;
				}
			}
			if(!f[tu[i].a] && !f[tu[i].b]){
				int x=find1(tu[i].a),y=find1(tu[i].b);
				if(x!=y){
					fa1[x]=y;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(fa[i]==i && f[i]){
				cnt++;
			}
		}
		if(cnt>2){
			return;
		}
		int maxss[1005],tt[1005],inx=0;
		for(int i=1;i<=n;i++){
			maxss[i]=1e18;
		}
		for(int i=1;i<=n;i++){
			if(f[i]==0) continue;
			int o=arr[i].size();
			for(int j=0;j<o;j++){
				int v=arr[i][j];
				if(f[v]) continue;
				maxs=0;
				dfs1(v,i);
				int b=find1(v);
				tt[++inx]=b;
				maxss[b]=min(maxss[b],maxs);
			}
			for(int k=1;k<=n;k++){
				dp[k]=0;
			}
		}
		int mx=0;
		for(int i=1;i<=inx;i++){
			mx=max(maxss[tt[i]],mx);
		}
		mins=min(mins,mx); 
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		dfs(x+1);
		f[i]=0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		mins=1e18;
		for(int i=1;i<=n;i++){
			arr[i].clear();
		}
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>tu[i].a>>tu[i].b;
			arr[tu[i].a].push_back(tu[i].b);
			arr[tu[i].b].push_back(tu[i].a);
		}
		dfs(1);
		cout<<mins<<"\n";
	}
	return 0;
}
