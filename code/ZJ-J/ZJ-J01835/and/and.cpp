#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2e5+10;
ll n,ans,m;
ll a[MAXN];
void dfs(ll nd,ll s,ll c){
	if(c<=0){
		ans=max(ans,s);
		return;
	}
	if(nd>n) return;
	dfs(nd+1,s&a[nd],c-1);
	dfs(nd+1,s,c);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0x7fffffff,m);
	cout<<ans;
	return 0;
}
