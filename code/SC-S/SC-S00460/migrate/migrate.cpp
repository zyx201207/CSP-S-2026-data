#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;

int n,d;
vector<pii>v[200005];
int a[200005],dis[200005],vis[200005],cnt[200005],sum[200005],ans=0;

void dij(int s){
	memset(dis,0x3f,sizeof dis);
	for(int i=0;i<2e5+5;i++){
		vis[i]=cnt[i]=sum[i]=0;
	}
	priority_queue<pii,vector<pii>,greater<pii> >q;
	dis[s]=0;
	q.push({0,s});
	while(q.size()>0){
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		for(auto e:v[u]){
			int vv=e.first,w=e.second;
			if(vis[vv])continue;
			if(dis[vv]>dis[u]+w){
				dis[vv]=dis[u]+w;
				q.push({dis[vv],vv});
				cnt[vv]=1;
				sum[vv]=0;
			}
			else if(dis[vv]==dis[u]+w){
				cnt[vv]++;
				if(cnt[vv]==2){
					sum[vv]++;
				}
				if(cnt[vv]==3){
					sum[vv]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=sum[i];
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _,t;
	cin>>_>>t;
	
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			v[i].clear();
		}
		for(int i=1;i<=n;i++){
			int x=a[i]+d;
			for(int j=i+1;j<=n&&a[j]<=x;j++){
				v[i].push_back({j,a[j]-a[i]});
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}