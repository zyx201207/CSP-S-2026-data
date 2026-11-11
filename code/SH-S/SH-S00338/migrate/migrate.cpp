#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=2e6+10,M=5010;
ll n,a[N],dis[M][M],cnt[M][M];
bool book[N];
vector<int> g[N];
priority_queue<PII,vector<PII>,greater<PII>> heap;
void dijkstra(int s){
	for(int i=1;i<=n;i++) book[i]=0;
	dis[s][s]=0;
	cnt[s][s]=1;
	heap.push({0,s});
	while(!heap.empty()){
		auto t=heap.top();
		heap.pop();
		int u=t.second;
		if(book[u]) continue;
		book[u]=1;
		for(auto v:g[u]){
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				cnt[s][v]=cnt[s][u];
				heap.push({dis[s][v],v});
			}
			else if(dis[s][v]==dis[s][u]+1){
				cnt[s][v]+=cnt[s][u];
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll c,t,d,ans;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=0x7f;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			dijkstra(i);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}

