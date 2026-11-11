#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
	queue<ll> idx;
	ll maxi;
};
ll C,T,n,d,x[2000005],dp[2000005];
deque<node> dq;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(C>=15&&C<=18){
			ll t=d/abs(x[2]-x[1]);
			ll ans=0;
			for(ll i=1;i<=n;i++){
				ll tem=max(min(t,i)/2-1,0ll);
				ans+=tem;
			}
			cout<<ans<<"\n";
			continue;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			while(!dq.empty()) dq.pop_back();
			for(int j=1;j<=n;j++) dp[j]=0;
			for(int j=i;j<=n;j++){
				while(!dq.empty()&&x[dq.front().idx.back()]<x[j]-d) dq.pop_front();
				while(!dq.empty()&&x[dq.front().idx.front()]<x[j]-d) dq.front().idx.pop();
				if(!dq.empty()){
					if((int)dq.front().idx.size()==2){
						ans++;
					}
					dp[j]=dp[dq.front().idx.back()]+1;
				}else{
					if(j!=i) break;
				}
				while(!dq.empty()&&dp[dq.back().idx.back()]>dp[j]) dq.pop_back();
				if(!dq.empty()&&dp[dq.back().idx.back()]==dp[j]){
					dq.back().idx.push(j);
				}else{
					node tem;
					tem.idx.push(j);
					dq.push_back(tem);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
