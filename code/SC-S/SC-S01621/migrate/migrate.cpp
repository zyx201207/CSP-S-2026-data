#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
ll c,t,n,d,ans,a[2000001],rd[2000001],bf[2000001];vector<ll> ds[2000001];
pair<ll,ll> ps[2000001];queue<ll> pq;
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;while(t--){
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>a[i],rd[i]=0;
		for(ll i=1;i<=n;i++){
			ds[i].clear();
			for(ll j=i+1;j<=n;j++)if(a[j]<=a[i]+d)ds[i].push_back(j),rd[j]++;
		}
		for(ll i=1;i<=n;i++){
			for(ll j:ds[i-1])rd[j]--;
			for(ll j=i+1;j<=n;j++)bf[j]=rd[j],ps[j]={1e18,0};
			pq.push(i);ps[i]={0,1};
			while(!pq.empty()){
				ll u=pq.front();pq.pop();
				if(ps[u].second==2)ans++;
				for(ll nxt:ds[u]){
					rd[nxt]--;
					if(ps[nxt].first>ps[u].first+1)
						ps[nxt].first=ps[u].first+1,
						ps[nxt].second=ps[u].second;
					else if(ps[nxt].first==ps[u].first+1)
						ps[nxt].second+=ps[u].second;
					if(!rd[nxt])pq.push(nxt);
				}
			}
			for(ll j=i;j<=n;j++)rd[j]=bf[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6*/