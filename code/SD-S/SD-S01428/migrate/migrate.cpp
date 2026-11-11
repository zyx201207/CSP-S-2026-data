#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dis[2000005];
map<ll,ll>mp;
ll n,d;
ll minn;
void dfs(ll s,ll t,ll sum){
	if(s==t){
		if(minn>sum){
			minn=sum;
		}
		mp[minn]++;
		return;
	}
	ll add=1;
	while(s+add<=t&&dis[s+add]-dis[s]<=d){
		dfs(s+add,t,sum+1);
		add++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll c,t;
	cin>>c>>t;
	ll res;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>dis[i];
		}
		res=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+3;j<=n;j++){
				minn=INT_MAX;
				dfs(i,j,0);
				if(mp[minn]==2){
					res++;
				}
				mp.clear();
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

