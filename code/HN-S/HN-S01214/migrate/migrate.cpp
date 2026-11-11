#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int idx,dist;
	bool operator < (const node& x) const{
		return dist>x.dist;
	}
};
const int INF=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,u,v,a[305],dist[305],cnt[305];
bool vis[305];
vector<int> ve[305],wi[305];
void dijk(int x){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt)); 
	priority_queue<node> qu;
	qu.push((node){x,0});
	dist[x]=0;
	while(qu.size()){
		node sn=qu.top();
		qu.pop();
		u=sn.idx;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<ve[u].size();i++){
			v=ve[u][i];
			if(dist[v]>dist[u]+wi[u][i]){
				dist[v]=dist[u]+wi[u][i];
				qu.push((node){v,dist[v]});
				cnt[v]=1;
			}else if(dist[v]==dist[u]+wi[u][i]){
				cnt[v]++;
			}
		}
	}
}
void clean(){
	for(int i=1;i<=n;i++){
		dist[i]=0;
		vis[i]=0;
		cnt[i]=0;
		ve[i].clear();
		wi[i].clear();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		clean();
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					ve[i].push_back(j);
					wi[i].push_back(1);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijk(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2ll){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
