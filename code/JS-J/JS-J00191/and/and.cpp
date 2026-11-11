#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
ll n,m;
ll ans=0;
ll a[N];
bool vis[N];
void dfs(ll w,ll pos){
	if(pos>m){
		ans=max(ans,w);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(w&a[i],pos+1);
			vis[i]=0;
		}
	}
	return;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	cout<<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
