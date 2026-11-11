#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int inf=1e9;
int n,k;
int ans;
bool res[N];
int vis[N];
vector<int> G1[N],G2[N];
void dfsBel(int u){
	for(int i=0;i<G2[u].size();i++){
		int v=G2[u][i];
		if(vis[v]!=-1) continue;
		vis[v]=vis[u]+1;
		dfsBel(v);
	}
}
void dfsDis(int u){
	for(int i=0;i<G1[u].size();i++){
		int v=G1[u][i];
		if(vis[v]!=-1) continue;
		vis[v]=vis[u]+1;
		dfsDis(v);
	}
}
void dfs(int now,int cnt){
	if(cnt>k) return ;
	if(now==n+1){
		for(int i=1;i<=n;i++) vis[i]=-1;
		for(int i=1;i<=n;i++) G2[i].clear();
		for(int u=1;u<=n;u++){
			if(!res[u]) continue;
			for(int i=0;i<G1[u].size();i++){
				int v=G1[u][i];
				if(res[v]){
					G2[u].push_back(v);
					G2[v].push_back(u);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==-1&&res[i]){
				cnt++;
				vis[i]=0;
				dfsBel(i); 
			}
		}
		if(cnt>2) return ;
		int maxv=0;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++) vis[i]=-1;
			vis[j]=0;
			dfsDis(j);
			int minv=inf;
			for(int i=1;i<=n;i++) if(res[i]) minv=min(minv,vis[i]-vis[j]);
			maxv=max(maxv,minv);
		} 
		ans=min(ans,maxv);
		return ;
	}
	res[now]=1;
	dfs(now+1,cnt+1);
	res[now]=0;
	if(cnt+n-now>=k) dfs(now+1,cnt);
}
void BF(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) G1[i].clear(), G2[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G1[u].push_back(v);
		G1[v].push_back(u);
	}
	ans=inf;
	dfs(1,0);
	cout<<ans<<endl;
	return ;
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c,T=1; cin>>c>>T;
	while(T--) BF();
	return 0;
}  
/*
0 2
 5 2
 1 2
 2 3
 3 4
 4 5
 10 3
 1 2
 1 3
 2 4
 2 5
 3 6
 3 7
 3 8
 7 9
 9 10
*/
