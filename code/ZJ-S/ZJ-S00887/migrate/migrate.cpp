#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d,ans,a[2000005],dis[5005][5005],vis[5005],cnt[5005][5005];
priority_queue<pair<ll,ll> >q;
bool G[5005][5005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)G[i][j]=0;
		}
		for(int i=1; i<=n; i++) {
			ll x=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			for(int j=i+1; j<=x; j++) {
				G[i][j]=1;
				G[j][i]=1;
			}
		}
		memset(cnt,0,sizeof(cnt));
		memset(dis,0x7f,sizeof(dis));
		for(int i=1; i<=n; i++) {
			dis[i][i]=0;
			q.push({0,i});
			memset(vis,0,sizeof(vis));
			while(!q.empty()) {
				int u=q.top().second;
				q.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(int j=1;j<=n;j++){
					if(!G[u][j])continue;
					if(dis[i][u]+1<dis[i][j]) {
						cnt[i][j]=0;
						dis[i][j]=dis[i][u]+1;
						q.push({-dis[i][j],j});
					}
					if(dis[i][u]+1==dis[i][j]) cnt[i][j]++;
				}
			}
		}
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
