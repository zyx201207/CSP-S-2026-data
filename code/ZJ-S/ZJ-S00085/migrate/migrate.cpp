#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,t,n,d,x[N],vis[5005][3],id[5005];
vector<ll> mp[N];
queue<ll> q;
void bfs(ll num){
	q.push(num);
	ll len=0;
	while(q.size()){
		len++;
		ll sum=q.size();
		while(sum--){
			ll qf=q.front();
			for(ll j=0;j<mp[qf].size();j++){
				ll i=mp[qf][j];
				if(id[i]<3){
					vis[i][id[i]++]=len;
//					cout<<i<<" "<<id[i]<<" "<<vis[i][0]<<"*\n";
					q.push(i);
				}
			}
			q.pop();
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll ans=0;
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(ll i=1;i<=n;i++){
//			ll l=lower_bound(x+1,x+1+n,x[i]-d)-x;
			ll r=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
//			if(l<i)mp[i].push_back(l++);
//			if(l<i)mp[i].push_back(l++);
//			if(l<i)mp[i].push_back(l++);
			if(r>i)mp[i].push_back(r--);
			if(r>i)mp[i].push_back(r--);
			if(r>i)mp[i].push_back(r--);
//			cout<<mp[i].size()<<" ";
		}
//		cout<<"-\n";
		for(ll i=1;i<=n;i++){
			memset(vis,-1,sizeof vis);
			memset(id,0,sizeof id);
			bfs(i);
//			cout<<i<<":\n";
//			cout<<vis[2][0]<<"\n";
			for(ll j=i+1;j<=n;j++){
//			cout<<vis[j][0]<<" "<<vis[j][1]<<" "<<vis[j][2]<<"\n";
				if(vis[j][0]!=-1&&vis[j][1]==vis[j][0]&&vis[j][1]!=vis[j][2]){
					ans++;
				}
				
			}
//			cout<<'\n';
		}
		for(ll i=1;i<=n;i++)mp[i].clear();
		printf("%lld\n",ans);
	}
	return 0;
}
