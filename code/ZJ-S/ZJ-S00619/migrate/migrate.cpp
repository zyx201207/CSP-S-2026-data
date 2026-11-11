#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010;
ll a[N],nxt[N],vis[N],p[N][N];
vector<ll>g[N];
int cnt=0;
void bfs(int st,int ed){
	queue<pair<int,int>>q;
	q.push({st,0});
	ll ans=0,mx=0;
	while(!q.empty()){
		ll u=q.front().first;
		ll step=q.front().second;
		q.pop();
		vis[u]=1;
		if(u==ed&&mx==0){
			ans++;
			mx=step;
		}else if(step==mx&&u==ed){
			ans++;
		}
		if(step>mx&&mx!=0)continue;
		for(int i=0;i<g[u].size();i++){
			ll v=g[u][i];
			if(vis[v])continue;
			q.push({v,step+1});
		}
	}
	if(ans==2)cnt++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){	
		cnt=0;
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				p[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]<=a[i]+d){
					if(p[i][j])continue;
					g[i].push_back(j);
					g[j].push_back(i);
					p[i][j]=1;
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,sizeof(vis));
				bfs(i,j);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}