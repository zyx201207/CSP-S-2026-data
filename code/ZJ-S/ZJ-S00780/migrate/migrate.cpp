#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
int n,d;
long long x[100005],ans=0;
vector<int>e[100005];
long long dis[5005][5005],cnt[5005][5005];
bool vis[5005][5005];
long long ne[5005];
void dij(int s,int l){
	for(int i=1;i<=n;i++){
		ne[i]=d;
		cnt[l][i]=0;
		dis[l][i]=1e18;
		vis[l][i]=0;
	}
	priority_queue<pair<long long,int> >pq;
	pq.push({0,s});
	dis[l][s]=0;
	cnt[l][s]=1;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[l][u])continue;
		vis[l][u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(dis[l][u]+1<dis[l][v]){
				dis[l][v]=dis[l][u]+1;
				cnt[l][v]=1;
				pq.push({-dis[l][v],v});
			}else if(dis[l][u]+1==dis[l][v]&&ne[u]!=0&&abs(u-v)>d){
				ne[u]--;
				//
				cnt[l][v]+=cnt[l][u];
				pq.push({-dis[l][v],v});
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				e[i].push_back(j);
//				e[j].push_back(i);
			}else{
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i,i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<cnt[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
//				cout<<i<<" "<<j;
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
I_don_t_want_to_AFO{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
	int p;
	cin>>p>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}
