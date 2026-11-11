#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=2e6+10,inf=1e18;
ll a[biao],n,d,tid,mod[2];
ll dis[biao],cnt[biao][2];

void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll mx=i;
		cnt[i-1][0]=cnt[i-1][1]=0;
		dis[i]=0;
		for(ll j=i+1;j<=n;j++) dis[j]=inf,cnt[j][0]=cnt[j][1]=0;
		for(ll num=0;num<2;num++) cnt[i][num]=1,cnt[i+1][num]=mod[num]-1;
		
		for(ll j=i;j<=n;j++){
			if(dis[j]==inf) break;
			for(ll num=0;num<2;num++){
				cnt[j][num]+=cnt[j-1][num];
				if(cnt[j][num]>=mod[num]) cnt[j][num]-=mod[num];
			}
			if(cnt[j][0]==2 && cnt[j][1]==2) ans++;
			ll l=i,r=n+1;
			while(l+1<r){
				ll mid=l+r>>1;
				if(a[mid]-a[j]<=d) l=mid;
				else r=mid;
			}
			
			ll now=l;
			if(now>mx){
				for(ll k=mx+1;k<=now;k++) dis[k]=dis[j]+1;
				mx=now;
			}
			
			l=i,r=now+1;
			while(l+1<r){
				ll mid=l+r>>1;
				if(dis[mid]<dis[j]+1) l=mid;
				else r=mid;
			}
			for(ll num=0;num<2;num++){
				cnt[r][num]=cnt[r][num]+cnt[j][num];
				if(cnt[r][num]>=mod[num]) cnt[r][num]-=mod[num];
				cnt[now+1][num]-=cnt[j][num];
				if(cnt[now+1][num]<0) cnt[now+1][num]+=mod[num];
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	mod[0]=1e9+207,mod[1]=1e9+321;
	
	ll t;
	cin>>tid>>t;
	while(t--) solve();
	
	return 0;
}
