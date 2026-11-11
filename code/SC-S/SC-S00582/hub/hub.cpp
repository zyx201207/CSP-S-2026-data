#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10,inf=1e9+10;

ll op,n,m,c1,c2,tx,ans=inf;
//ll dep1[N],dep2[N],dep3[N];
ll dep[N],b[N];
vector<ll> node[N];
priority_queue<ll>qe;
void find(ll u,ll fa,ll d=0){
	dep[u]=min(dep[u],d);
	for(auto v:node[u]){
		if(v==fa) continue;
		find(v,u,dep[u]+1);
	}
}
void dfs(ll x,ll sum){
	if(x>n){
		if(sum!=0) return;
		for(int i=1;i<=n;i++) dep[i]=inf;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				find(i,0);
			}
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cnt=max(cnt,dep[i]);
		}
		ans=min(ans,cnt);
		return;
	}
	dfs(x+1,sum);
	if(sum==0) return;
	b[x]=1;
	dfs(x+1,sum-1);
	b[x]=0;
}
//void dfs(ll u,ll fa,ll c,ll dep=1){
//	if(dep>tx) {
//		tx=dep;
//		if(c==1) c1=u;
//		else c2=u;
//	}
//	for(auto v:node[u]){
//		if(v==fa) continue;
//		dfs(v,u,c,dep+1);
//	}
//}
//void dfs1(ll u,ll fa,ll c){
//	if(c==1) dep1[u]=dep1[fa]+1;
//	else dep2[u]=dep2[fa]+1;
//	for(auto v:node[u]){
//		if(v==fa) continue;
//		dfs1(v,u,c);
//	} 
//}
//void dfs2(ll u,ll fa,ll dep=0){
//	if(qe.size()<m) qe.push(dep);
//	else if(qe.top()>dep) {
//		qe.pop();
//		qe.push(dep);
//	}
//	else return;
//	for(auto v:node[u]){
//		if(v==fa) continue;
//		dfs2(v,u,dep+1);
//	}
//}
//void dfs3(ll u,ll fa,ll dep=0){
//	dep3[u]=min(dep3[u],dep);
//	for(auto v:node[u]){
//		if(v==fa) continue;
//		dfs3(v,u,dep+1);
//	}
//}
//void dfs4(ll u,ll fa,ll dep=0){
//	qe.push(dep);
//	while(qe.size()>m){
//		qe.pop();
//	}
////	cout<<u<<":"<<dep<<"\n";
//	if(qe.top()<dep) return;
//	for(auto v:node[u]){
//		if(v==fa) continue;
//		dfs4(v,u,dep+1);
//	}
//}
void solve(){
	cin>>n>>m;
	if(op>=13&&op<=14){
		cout<<(n-m+2)/3<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		node[i].clear();
	}
	for(int i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	dfs(1,m);
	cout<<ans<<'\n';
//	tx=0;
//	dfs(1,0,1);tx=0;
//	dfs(c1,0,2);
//	dfs1(c1,0,1);
//	dfs1(c2,0,2);
//	if(m==2){
//		s1();
//		return;
//	}
//	if(m==1){
//		s2();
//		return;
//	}
//	cout<<c1<<" "<<c2<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<i<<":"<<dep1[i]<<" "<<dep2[i]<<'\n';
//	}
//	for(int i=1;i<=n;i++){
//		if(abs(dep1[i]-dep2[i])<=1&&(dep1[i]+dep2[i]-1)==dep1[c2]){
//			cout<<i<<" ";
//			dfs2(i,0);
//			ll x=qe.top();qe.pop();
//			ans=min(ans,qe.top()+x);
//			while(qe.size()) qe.pop();
//		}
//	}
//	ll ans=inf;
//	for(int i=1;i<=n;i++){
//		dfs4(i,0);
//		ll x=qe.top();
//		qe.pop();
//		ans=min(ans,x+qe.top());
//		while(qe.size()) qe.pop();
////		cout<<ans<<" ";
//	}
//	cout<<ans<<"\n";
}
void cl(){
	for(int i=1;i<=n;i++){
//		dep1[i]=dep2[i]=0;
		node[i].clear();
	}
	c1=c2=0;tx=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>op>>t;
	while(t--){
		solve();
		cl();
	}
	return 0;
} 
