#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
vector<int> ve[maxn];
int cnt,a[maxn],p[maxn][maxn],dis[maxn][maxn],d[maxn],vis[maxn];
int n,k;
int ffans=1e18;
void dfs(int x,int y){
	if(y>k)return;
	if(x>n+1)return;
	if(y==k){
		memset(vis,0,sizeof vis);
		for(int i=1;i<=cnt;i++){
			for(int j=i+1;j<=cnt;j++){
				ve[i].push_back(j),ve[j].push_back(i);
			}
		}
		int ans=0;
		for(int i=1;i<=cnt;i++){
			if(!vis[i]){
				ans++;
				queue<int> qu;
				while(!qu.empty()){
					int x=qu.front();qu.pop();
					for(int y:ve[x]){
						if(!vis[y]){
							vis[y]=1;
							qu.push(y);
						}
					}
				}
			}
		}
		if(ans!=2)return;
		for(int i=1;i<=cnt;i++){
			queue<int> qu;
			vis[i]=1;
			memset(vis,0,sizeof vis);
			qu.push(i);
			while(!qu.empty()){
				int x=qu.front();
				qu.pop();
				for(int y:ve[x]){
					if(!vis[y]){
						vis[y]=1;
						dis[i][y]=dis[i][x]+1;
					}
				}
			}
		} 
		int fans=-1;
		for(int i=1;i<=n;i++){
			bool f=0;
			for(int j=1;j<=cnt;j++)if(a[j]==i)f=1;
			if(f==1)continue;
			int ans=1e18;
			for(int j=1;j<=n;j++){
				//cout<<dis[i][j]<<" ";
				if(dis[i][j]!=0)ans=min(ans,dis[i][j]);
			}
			//cout<<ans<<" ";
			if(ans!=1e18)fans=max(fans,ans);
			//cout<<fans<<" ";
		}
		if(fans!=-1)ffans=min(ffans,fans);
		return;
	}
	a[++cnt]=x;
	dfs(x+1,y+1);
	cnt--;
	dfs(x+1,y);
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		ffans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
			p[u][v]=p[v][u]=1;
		}
		dfs(1,0);
		cout<<ffans<<"\n";
	}
	return 0;
}
