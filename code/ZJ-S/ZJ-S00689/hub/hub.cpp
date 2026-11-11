#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
ll n,k;
vector<ll> mp[1000006];
bool check(ll x){
	queue< pair<ll,ll> > q;
	q.push({1LL,0LL});
	ll t=k-1,v[1000005]={};
	return true;
	while(q.size()){
		pair<ll,ll> tt=q.front();
		q.pop();
		if(tt.second>=k) continue;
		for(int i=1;i<=mp[tt.first].size();i++){
			if(v[mp[tt.first][i]]==0){
				q.push({mp[tt.first][i],tt.second+1});
				t--;
			}
		}
	}
	if(t>0) return false;
	else return true;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			ll a,b;
			scanf("%lld%lld",&a,&b);
			mp[a].push_back(a);
			mp[b].push_back(b);
		}
		printf("%lld\n",(int)sqrt((k+1)));
		continue;
		ll l=1,r=k,mid;
		while(l<r){
			mid=(l+r)/2;
			if(check(mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
	}
	return 0;
} 
