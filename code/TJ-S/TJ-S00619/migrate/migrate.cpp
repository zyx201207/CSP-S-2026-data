#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
ll dfs(ll s,ll e,ll nw1,ll nw2,ll len,ll sum,ll mx,ll cnt,vector<ll>& mp){
	if(cnt>mx)return 0;
	if(s>=e) return 1;
	for(ll i=s;i<=e;i++){
		sum+=mp[i];
		if(sum>nw2){cnt++;nw2=mx;}
		len+=dfs(i,e,i,nw2-sum,0,0,mx,cnt,mp);
	} 
	return len;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t,n,d,tmp;cin>>c>>t;
	vector<ll> x;
	while(t--){
		cin>>n>>d;x.clear();
		for(ll i=1;i<=n;i++){
			cin>>tmp;x.push_back(tmp);
		}
		
		for(ll i=1;i<=n;i++){
			for(ll j=i+2;j<=n;j++){
				ll sum=0,mn=0;
				for(ll k:x){
					sum+=k;
					if(sum>=d){
						sum-=d;mn++;
						if(sum>=d) break;
					}
				}
				
				dfs(i,j,i,d,0,0,d,0,x);
			}
		}
		
	}
	return 0;
}
