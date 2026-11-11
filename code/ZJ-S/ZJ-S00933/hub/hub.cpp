#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,k;
ll a[4010][4010];
ll v[4010],vis[4010];
ll len[4010][4010];
ll s[4010];
ll ans=2e9;
void dfs(ll xx,ll x,ll l){
	vis[x]=1;
	for(ll i=1;i<=n;i++){
		if(a[x][i]==1&&vis[i]==0){
			//cout<<x<<" "<<i<<"\n";
			len[xx][i]=l;
			len[i][xx]=l;
			dfs(xx,i,l+1);
		}
	}
	return;
}
void zs(ll x,ll c){
	if(x==n+1){
		if(c!=k)return;
		ll cnt=0,tot=0;
		memset(s,0,sizeof(s));
		for(ll i=1;i<=n;i++){
			if(v[i]==1){
				s[++tot]=i;
			}
		}
		for(ll i=1;i<=n;i++){
			if(v[i]==1)continue;
			ll sum=2e9;
			for(ll j=1;j<=tot;j++){
				sum=min(sum,len[i][s[j]]);
			}
			cnt=max(sum,cnt);
		}
		ans=min(ans,cnt);
		return;
	}
	if(c<k){
		v[x]=1;
		zs(x+1,c+1);
	}
	v[x]=0;
	zs(x+1,c);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(a,0,sizeof(a));
		for(ll i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				len[i][j]=2e9;
			}
		}
		for(ll i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			dfs(i,i,1);
		}
		zs(1,0);
		cout<<ans<<"\n";
	}
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/