//RP+=INF
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll vis[200005];
ll ans;
int dfs(ll last,ll num){
	if(last==0){
		ans=max(ans,num);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(last-1,num&a[i]);
			vis[i]=0;
		}
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(m-1,a[i]);
		vis[i]=0;
	}
	printf("%lld",ans);
	return 0;
}
/*
5 3
31 3 1 15 7
*/