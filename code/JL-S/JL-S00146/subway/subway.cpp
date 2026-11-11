#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Station{
	vector<ll> road;
	vector<ll> t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ll c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	vector<ll> w(m+1);
	vector<Station> sta(m+1);
	for(ll i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		while(k--){
			ll a,t;
			cin>>a>>t;
			sta[a].road.push_back(i);
			sta[a].t.push_back(t);
		}
	}
	while(q--){
		ll x,y,ans=LONG_LONG_MAX;
		scanf("%lld%lld",&x,&y);
		for(size_t i=0;i<sta[x].road.size();i++){
			ll res=w[x]+sta[x].t[i];
			for(size_t j=0;j<sta[y].road.size();j++){
				if(sta[x].road[i]==sta[y].road[j]){
					res+=(w[y]+sta[y].t[j]);
				}else{
					for(ll k=1;k<=m;k++){
						if(k==x||k==y)continue;
						for(size_t ii=0;ii<sta[k].road.size();ii++){
							if(sta[k].road[ii]==sta[x].road[i]){
								for(size_t jj=0;jj<sta[k].road.size();jj++){
									if(sta[k].road[jj]==sta[y].road[j]){
										res+=sta[k].t[ii]+sta[k].t[jj]+sta[y].t[j]+w[y];
										break;
									}
								}
								break;
							}
						}
					}
				}
			}
			ans=min(ans,res);
		}
		printf("%lld\n",ans);
	}

	return 0;
}

