#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int c,t;

int n,k;

int ans=1e9;

vector<int> g[N];

int vis[N];

int vvis[N];

void dfs1(int u){
	vvis[u]=1;
	for(auto v:g[u]){
		if(vvis[v]) continue;
		if(!vis[v]) continue;
		dfs1(v);
	}
}

int b[50][50];
int a[50][50];

void solve(){
	
	for(int i=1;i<=n;i++) vvis[i]=0;
	
	int tot=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&!vvis[i]){
			dfs1(i);
			tot++;
		}
		for(int j=1;j<=n;j++){
			a[i][j]=b[i][j];
		}
	}
	
	if(tot>2) return;
//	cout<<tot<<"\n";
	for(int tt=1;tt<=n;tt++)
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	
	int res=0;
	for(int i=1;i<=n;i++){
		int cnt=1e9;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				cnt=min(cnt,a[i][j]);
			}
		}
		res=max(res,cnt);
	}
	
	ans=min(ans,res);
	
	return;
	
}

void f(int x){
	if(x>k){
		solve();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		f(x+1);
		vis[i]=0;
	}
	
	return;
}

signed main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>t;
	
	while(t--){
		
		cin>>n>>k;
		
		memset(b,0x3f,sizeof b);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			b[u][v]=1;
			b[v][u]=1;
		}
		
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<b[i][j]<<" ";
//			}cout<<"\n";
//		}
		
		f(1);
		
		cout<<ans<<"\n";
		
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		
	}
	
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