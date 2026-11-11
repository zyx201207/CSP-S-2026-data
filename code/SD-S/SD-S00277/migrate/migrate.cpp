#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int l;
int a[200005];
int dis[200005];
int cnt[200005];
int n,d;
bool vis[200005];
vector<int> t[20005];
const int INF=1e18;
void dijkstra(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(int i=0;i<=n;i++){
		dis[i]=INF,cnt[i]=0; 
	}
	dis[x]=0;
	cnt[x]=1;
	pq.push({0,x});
	while(!pq.empty()){
		int dist=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		for(auto v:t[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				cnt[v]=1;
				pq.push({dis[v],v});
			}
			else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>l;
	while(l--){
		cin>>n>>d;
		for(int i=0;i<10004;i++){
			t[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					t[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=i+2;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

