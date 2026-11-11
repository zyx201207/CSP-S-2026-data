#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+29;
const ll M=3e5+29;
ll n,m,t,cnt,ff,fff;
ll a[N],to[N],vv[N],vis[N],ans[M];
vector<ll> s[M];
void dfs(ll x,ll sum){
	if(vv[x]){
		fff=vv[x];
		cnt=sum;
		return;
	}
	if(x==n){
		vis[x]=1;
		fff=x,cnt=sum;
		return;
	}
	vis[x]=1;
	if(x==to[x]){
		if(x<ff) dfs(x+1,sum+1);
		else fff=x,cnt=sum;
	}else dfs(to[x],sum+1);
}
void dfs2(ll x,ll sum){
	vv[x]=sum;
	if(x==n) return;
	if(x==to[x]){
		if(x<ff) dfs2(x+1,sum);
	}else dfs2(to[x],sum);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]].push_back(i);
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<s[i].size();j++){
			ll x=s[i][j],y=((j==s[i].size()-1)?s[i][j]:s[i][j+1]);
			to[x]=y;
		}
	}
	for(ll i=1;i<=n;i++){
		if(to[i]!=i) ff=i+1;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		dfs(i,1);
		dfs2(i,fff);
		for(ll j=fff;j<=n;j++){
			ans[a[j]]+=cnt;
		}
//		cout<<"------------------------------\n"<<i<<":\n";
//		cout<<"cnt:"<<cnt<<"    fff:"<<fff<<"\n";
//		for(ll j=1;j<=m;j++) cout<<ans[j]<<" ";
//		cout<<"\n\n xb:";
//		for(ll j=1;j<=n;j++) cout<<j<<" ";
//		cout<<"\nvis:";
//		for(ll j=1;j<=n;j++) cout<<vis[j]<<" ";
//		cout<<"\n to:";
//		for(ll j=1;j<=n;j++) cout<<to[j]<<" ";
//		cout<<"\n vv:";
//		for(ll j=1;j<=n;j++) cout<<vv[j]<<" ";
//		cout<<"\n";
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
//	cout<<"\n\n";
//	for(ll i=1;i<=n;i++) cout<<to[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
