#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5; 
int C,t;
int n,k;
int ans;
int dis[N];
int len[N];
int mi[N];
vector<int> vt[N];
bool vis[N],now[N]; 
void dfs(int x,int ff){
	vis[x]=1;
	for(int v:vt[x]){
		if(v==ff||!now[v]) continue;
		dfs(v,x);
	}
}
void dfs2(int x,int ff){
	for(int v:vt[x]){
		if(v==ff) continue;
		dis[v]=dis[x]+1;
		dfs2(v,x);
	}
}
void solve(){
	cin>>n>>k;
	if(n>=20){
		cout<<1<<"\n";
		return ;
	}
	ans=n;
	for(int i=1;i<=n;i++) vt[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		vt[u].push_back(v);
		vt[v].push_back(u); 
	}
	for(int i=1;i<(1<<n);i++){
		len[i]=len[i&(i-1)]+1;
		if(len[i]!=k) continue;
		for(int j=1;j<=n;j++) now[j]=vis[j]=0;
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))) now[j]=1;
		int num=0;
		for(int j=1;j<=n;j++){
			if(vis[j]||!now[j]) continue;
			num++;
			dfs(j,0);
		}
		if(num>2) continue;
		int sum=0;
		for(int j=1;j<=n;j++){
			dis[j]=0;
			mi[j]=n;
			dfs2(j,0);
			for(int k=1;k<=n;k++) if(now[k]) mi[j]=min(mi[j],dis[k]);
			sum=max(sum,mi[j]);
		} 
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>C>>t;
	while(t--) solve();
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
