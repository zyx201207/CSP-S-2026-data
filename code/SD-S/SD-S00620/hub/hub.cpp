#include<bits/stdc++.h>
#define int long long
#define ys ios::sync_with_stdio(0);
#define mc cin.tie(0);
#define zmdNB cout.tie(0);
#define endl "\n"
using namespace std;
const int N=10+10;
int n,m,q,t,C,k,u,v,ans;
bool is[N],vis[N];
vector<int> a[N];
void dfs(int u,int fa){
	vis[u]=1;
	for(int v:a[u])if(v!=fa&&is[v])dfs(v,u);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ys mc zmdNB
	cin>>C>>t;
	while(t--){
		cin>>n>>k;
		ans=1e18;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i=0;i<(1<<n);i++){
			int cnt=0,ma=0;
			for(int j=0;j<n;j++)is[j+1]=i>>j&1,cnt+=i>>j&1,vis[j+1]=0;
			if(cnt!=k)continue;
			cnt=0;
			for(int j=1;j<=n;j++){
				if(is[j]&&!vis[j]){
					cnt++;
					dfs(j,0);
				}
			}
			if(cnt>2)continue;
			for(int j=1;j<=n;j++){
				if(is[j])continue;
				for(int k=1;k<=n;k++)vis[k]=0;
				queue<pair<int,int>> d;
				d.push({j,0});
				vis[j]=1;
				while(!d.empty()){
					int u=d.front().first,w=d.front().second;
					d.pop();
					if(is[u]){
						ma=max(ma,w);
						break;
					}
					for(int v:a[u]){
						if(vis[v])continue;
						vis[v]=1;
						d.push({v,w+1});
					}
				}
			}
			ans=min(ans,ma);
		}
		cout<<ans<<endl;
	}
	return 0;
}


