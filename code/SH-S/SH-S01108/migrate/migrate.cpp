#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10;
ll c,t;
ll n,d;
ll a[N];
ll recl[N],recr[N];
ll cntl[N],cntr[N];
ll r,l;
vector<ll> road[N];
queue<ll> q;
ll dis[N],sum[N];
void bfs(ll s){
	for(ll i=1;i<=n;i++){
		dis[i]=LONG_LONG_MAX;
		sum[i]=0;
	}
	dis[s]=0;
	q.push(s);
	sum[s]=1;
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(auto v:road[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				sum[v]=sum[u];
				q.push(v);
			}else if(dis[v]==dis[u]+1) sum[v]+=sum[u];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			cin>>n>>d;
			for(ll i=1;i<=n;i++) road[i].clear();
			for(ll i=1;i<=n;i++) cin>>a[i];
			l=r=1;
			while(l<=n){
				while(r<=n && a[r]-a[l]<=d) r++;
				for(ll i=l+1;i<r;i++) road[l].push_back(i);
				l++;
			}
			ll ans=0;
			for(ll i=1;i<n;i++){
				bfs(i);
				for(ll j=i+1;j<=n;j++){
					if(sum[j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}else{
		while(t--){
			cin>>n>>d;
			for(ll i=1;i<=n;i++) cin>>a[i];
			r=l=1;
			while(l<=n){
				while(r<=n && a[r]-a[l]<=d) r++;
				recr[l]=r-1;
				l++;
			}
			l=r=n;
			while(r>=1){
				while(l>=1 && a[r]-a[l]<=d) l--;
				recl[r]=l+1;
				r--;
			}
			recr[0]=1;
			for(ll i=n;i>=1;i--){
				if(recr[i]<=recr[i-1]){
					cntr[i]=0;
					continue;
				}
				cntr[i]=recr[i]-recr[i-1]; 
				cntr[i]+=cntr[recr[i]];
			}
			recl[n+1]=n;
			for(ll i=1;i<=n;i++){
				if(recl[i]>=recl[i+1]){
					cntl[i]=0;
					continue;
				}
				cntl[i]=recl[i+1]-recl[i];
				cntl[i]+=cntl[recl[i]];
			}
			ll ans=0;
			for(ll i=1;i<n;i++){
				if(recr[i]<recl[i+1]) continue;
				if(recl[i+1]==i || recr[i]==i+1) continue;
				ans=ans+cntl[i+1]*cntr[i]; 
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
