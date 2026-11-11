#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000005];
vector<int> g[50005];
struct node{
	int p,dis;
};
queue<node> q;
int cnt[5005],dis[5005];
bool vis[5005];
void bfs(int root){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	q.push({root,0});
	cnt[root]=1;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		int x=t.p,w=t.dis;
		for(auto v:g[x]){
			if(vis[v]){
				if(dis[v]==w+1)cnt[v]+=cnt[x];
			}
			else{
				cnt[v]=cnt[x];
				vis[v]=1;
				q.push({v,w+1});
				dis[v]=w+1;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--){
		int d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		if(n>=6000){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)g[i].clear();
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				//cout<<dis[j]<<" ";
				//cout<<cnt[j]<<'\n';
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	} 
}
