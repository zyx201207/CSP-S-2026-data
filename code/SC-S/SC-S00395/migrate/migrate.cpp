#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 2e6+5;
ll c,T;
ll a[maxn];
int dd[15][15];
int f[15];
void dfs(int u,int v,int st,ll n,ll d){
	if(f[v]>st){
		f[v]=st;
		dd[u][v]=1;
	}else if(f[v]==st){
		dd[u][v]++;
	}
	for(int i=v+1;i<=n;i++){
		if(a[i]-a[v]<=d){
			dfs(u,i,st+1,n,d);
		}
	}
}
void solve1(ll n,ll d){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dd[i][j]=0;
		}
		f[i] = 999999;
	}
	for(int i=1;i<n;i++){
		dfs(i,i,0,n,d);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dd[i][j]==2)ans++;
		}
	}
	cout<<ans<<endl;
}
void solve2(ll n,ll d){
	ll ans=0;
	for(ll i=4;i<=n;i++){
		if(a[i]-a[i-2]<=d&&a[i]-a[i-3]>d&&a[i-1]-a[i-3]<=d)ans++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=9)solve1(n,d);
		else solve2(n,d);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
