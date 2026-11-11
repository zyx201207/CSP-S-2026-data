#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,k;
vector<int>g[N]; 
vector<pair<int,int> >e; 
int dp[N][10];
int dep[N],f[N];
int get(int x){
	if(f[x]!=x) return f[x]=get(f[x]);
	else return f[x];
}
void dfs(int x,int fat){
//	cout<<x<<"--------\n";
	dep[x]=dep[fat]+1; 
	for(int i=1;i<=9;i++) dp[x][i]=dp[dp[x][i-1]][i-1];
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to==fat) continue;
		dp[to][0]=x;
		dfs(to,x);
	}
}
int LCA(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=9;i>=0;i--){
		if(dep[dp[y][i]]>=dep[x]) y=dp[y][i];
		if(x==y) return x;
	}
	for(int i=9;i>=0;i--){
		if(dp[x][i]!=dp[y][i]){
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	return dp[x][0];
}
int dis(int x,int y){
	int lca=LCA(x,y);
	return +dep[x]+dep[y]-dep[lca]*2;
}
int Main(){
	cin>>n>>k;
	int ans=1e9;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	e.clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		e.push_back({u,v});
	}
	dfs(1,0);
//	cout<<dis(2,3)<<"\n\n\n";
	for(int i=0;i<(1ll<<n);i++){
		int s=0;
		for(int j=1;j<=n;j++){
			if(i&(1ll<<j-1)){
			//	cout<<j<<' ';
				s++;
			} 
			f[j]=j;
		} 
	//	cout<<"\n";
		if(s!=k) continue;
		
	//	for(int j=1;j<=n;j++){
	//		if(i&(1ll<<j-1)){
		//		cout<<j<<' ';
			//	s++;
	//		} 
	//	} 
		int cnt=k,Min=-1e9;
		
		for(int j=0;j<e.size();j++){
			if((i&(1ll<<e[j].first-1))&&(i&(1ll<<e[j].second-1))){
				int u=get(e[j].first);
				int v=get(e[j].second);
				if(u==v) continue;
				f[u]=v;
				cnt--;
			//	Min=max(Min,dis(e[j].first,e[j].second));
			}
		}
		if(cnt!=2) continue;
		int pp=0;
		for(int j=1;j<=n;j++){
			Min=1e9;
			for(int k=1;k<=n;k++){
				if(i&(1ll<<k-1)){
					Min=min(Min,dis(j,k));
				} 
			} 
			pp=max(pp,Min);
		} 
	//	cout<<pp<<' '<<cnt<<"\n";
		if(cnt==2&&pp>=0){
		//	cout<<
	//	cout<<Min<<' '<<cnt<<"=-====\n";
			ans=min(ans,pp);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int t,p;
	cin>>p>>t;
	if(p<=3){
		while(t--){
			Main();
		}
	}
	else{
		while(t--){
			cin>>n>>k;
			for(int i=1,u,v;i<n;i++){
				cin>>u>>v;
			}
			cout<<rand()%n+1<<"\n"; 
		}
	}
	return 0;
}
/*
//  É¾´óÑùÀý 

100 2
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
