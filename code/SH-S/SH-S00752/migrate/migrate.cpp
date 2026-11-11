#include<bits/stdc++.h>
using namespace std;
#define N 2222222
#define int long long
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
struct Edge{int v,w;};
int c,t,n,d,a[N],vis[N],ans;
unordered_map<int,int>dis[N];
vector<int>e[N];
void bfs(int s){
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s);
	dis[s][s]=1;
	while(q.size()){
		int l=q.front();q.pop();
		if(dis[s][l]>2)continue;
		ans+=(s<=l&&dis[s][l]==2);
		for(const auto&i:e[l]){
			if(!vis[i]||vis[i]==vis[l]+1){
				dis[s][i]+=dis[s][l];
				if(dis[s][i]<=2&&!vis[i])q.push(i);
				vis[i]=vis[l]+1;
			}
		}
	}
}
void work(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],e[i].clear();
	for(int i=1;i<=n;i++)unordered_map<int,int>().swap(dis[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1,r=upper_bound(a+1,a+1+n,a[i]+d)-a-1;j<=r;j++)
			e[i].push_back(j);
	for(int i=1;i<=n;i++)bfs(i);
	cout<<ans<<'\n';
}
signed main(){
	open("migrate");
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--)work();
	cout.flush();
}