#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5006;
int c,T,n,d,dis[N],vis[N],tot[N],a[N],ans;
vector<int> g[N];
void bfs(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(tot,0,sizeof(tot));
	queue<int>q;
	q.push(s);
	dis[s]=0;
	tot[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto y:g[x]){
			if(vis[y]){
				if(dis[x]+1==dis[y])tot[y]+=tot[x];
				continue;
			}
			dis[y]=dis[x]+1;
			tot[y]=tot[x];
			q.push(y);
			vis[y]=1;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d)g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				if(tot[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}