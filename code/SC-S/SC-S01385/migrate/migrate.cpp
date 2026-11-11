#include<bits/stdc++.h>
using ll=long long;
using namespace std;
struct node{
	int di,cnt;
}d[2010][2010];
int c,t;
int x[200010];
int vis[200010];
int n,f;
void bfs(int s,int step){
	queue<pair<int,int>> q;
	q.push({s,0});
	vis[s]=1;
	while(!q.empty()){
		auto [u,st]=q.front();
		q.pop();
		for(int v=1;v<=n;++v){
			if(u==v) continue;
			if(abs(x[u]-x[v])>f) continue;
			vis[v]=1;
			q.push({v,st+1});
			if(d[s][v].di==(st+1)) ++d[s][v].cnt;
			else if(d[s][v].di>(st+1)) d[s][v].di=st+1,d[s][v].cnt=1;
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>f;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				d[i][j].cnt=0;
				d[i][j].di=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			bfs(i,0);
		}
		int ans=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j){
					if(d[i][j].cnt==2) ++ans;
				}
			}
		}
		cout<<ans/2<<"\n";
	}
}