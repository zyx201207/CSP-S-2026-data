#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int m,q,c,w[N],tt,n,d,x[N],cnt[N],dis[N];
vector<int>G[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>tt;
	while(tt--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[i],G[i].clear(),cnt[i]=0,dis[i]=0;
		for(int i=1;i<=n;++i){
			int l=i+1;
			while(l<=n&&x[l]-x[i]<=d){
				G[i].push_back(l);
				l++;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			queue<int>q;
			q.push(i);
			for(int j=i+1;j<=n;++j){
				dis[j]=1e18;
				cnt[j]=0;
			}
			dis[i]=0;
			cnt[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				
				if(cnt[u]>2)continue;
				
				if(cnt[u]==2)ans++;
				for(auto t:G[u]){
					if(dis[t]==dis[u]+1){
						cnt[t]+=cnt[u];
					}
					else if(dis[t]>dis[u]){
						dis[t]=dis[u]+1;
						cnt[t]=cnt[u];
						q.push(t);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
