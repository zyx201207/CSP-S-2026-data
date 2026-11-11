#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll c,t,n,d,dis[2000005],ans,cnt[2000005],a[2000005];
bool vis[2000005];
void dj(ll x){
	memset(dis,0x7f,sizeof dis);
	dis[x]=0;
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	cnt[x]=1;
	priority_queue<pll,vector<pll>,greater<pll> >pq;
	pq.push({0,x});
	while(pq.size()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(ll i=u-1;i>=1;i--){
			if(a[u]-a[i]<=d){
				if(dis[i]>dis[u]+1){
					dis[i]=dis[u]+1;
					cnt[i]=cnt[u];
					pq.push({dis[i],i});
				}else if(dis[i]==dis[u]+1)cnt[i]+=cnt[u];
			}else break;
		}
		for(ll i=u+1;i<=n;i++){
			if(a[i]-a[u]<=d){
				if(dis[i]>dis[u]+1){
					dis[i]=dis[u]+1;
					cnt[i]=cnt[u];
					pq.push({dis[i],i});
				}else if(dis[i]==dis[u]+1){
					cnt[i]+=cnt[u];
					pq.push({dis[i],i});
				}
			}else break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>a[i];
		ans=0;
		if(n>5000){
			ll cha=a[2]-a[1];
			if(d/cha<=1)cout<<0<<'\n';
			else{
				ll jian=d/cha;
				cout<<max(0ll,n-jian*2+1)<<'\n';
			}
			continue;
		}
		for(ll i=1;i<=n;i++){
			dj(i);
			for(ll j=i+1;j<=n;j++)ans+=(cnt[j]==2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
