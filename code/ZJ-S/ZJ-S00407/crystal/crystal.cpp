//‘∏¥À––£¨÷’µ÷»∫–« 
#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fir first
#define sec second
using namespace std;
map<ll,ll> dict;
ll n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll t;cin>>t;
		dict[t]++;
	}
	vector<pii>g(dict.begin(),dict.end());
	g.insert(g.begin(),make_pair(dict.begin()->fir,0));
	vector<ll>pre(g.size(),0);
	for(ll i=1;i<(ll)pre.size();i++){
		pre[i]=pre[i-1]+g[i].sec;
	}
	ll l=1,r=0;
	ll sum=0;
	for(ll i=1;i<(ll)pre.size();i++){
		r=i-1;
		sum+=(pre[r]-pre[l-1])*(g[i].fir-g[i-1].fir);
		ll tsum=sum;
		while(tsum>m && l<=r){
			ll k=min(g[l].sec,(ll)ceil(1.0*(tsum-m)/(g[i].fir-g[l].fir)));
			if(k==g[l].sec){
				tsum-=g[l].sec*(g[i].fir-g[l].fir);
				sum-=g[l].sec*(g[i].fir-g[l].fir);
				l++;
			}
			else{
				ans=max(ans,g[i].sec+pre[r]-pre[l-1]-k);
				goto skip;
			}
		}
		ans=max(ans,g[i].sec+pre[r]-pre[l-1]);
		skip:continue;
	}
	printf("%lld",ans);
	return 0;
}

