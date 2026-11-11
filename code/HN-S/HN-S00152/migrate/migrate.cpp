#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int n,d,a[maxn],sum[maxn],dis[maxn],ans;
bool f[maxn],vis[maxn];
struct edge{
	int v,w;
};
struct node{
	int u,d;
	bool operator<(const node&x)const{
		return d>x.d;
	}
};
vector<edge>e[maxn];
void dj(int s){
	for(int i=1;i<=n;i++)
		dis[a[i]]=INT_MAX,sum[a[i]]=vis[a[i]]=0;
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v,w=e[u][i].w;
			if(!vis[v]&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				sum[v]++;
				q.push({v,dis[v]});
			}else if(!vis[v]&&dis[v]==dis[u]+w){
				sum[v]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int id,T;
	cin>>id>>T;
	while(T--){
		cin>>n>>d;
		int www=LLONG_MAX;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			www=min(www,a[i]);
		}
		if(www<0)
			for(int i=1;i<=n;i++)
				a[i]=a[i]+abs(www)+1;
		for(int i=1;i<=n;i++)
			f[a[i]]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=d;j++){
				int v=a[i]+j;
				if(f[v])
					e[a[i]].push_back({v,1});
			}
		for(int i=1;i<=n;i++)
			f[a[i]]=0;
		for(int i=1;i<=n;i++){
			dj(a[i]);
			for(int j=1;j<=n;j++)
				if(sum[a[j]]==2)
					ans++;
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
			e[a[i]].clear();
		ans=0;
	}
	return 0;
}
