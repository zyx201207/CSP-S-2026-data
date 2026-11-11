#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,d,a[2000005],s[2000005],di[2000005];
void dfs(ll x,ll w){
	if(w<di[x]){
		di[x]=w,s[x]=1;
	}else if(w==di[x]){
		s[x]++;
	}
	for(ll i=x+1;i<=n;i++){
		if(abs(a[i]-a[x])<=d){
			dfs(i,w+1);
		}else{
			return;
		}
	}
}
int main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		ll sm=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				s[j]=0;
				di[j]=1e18;
			}
			dfs(i,0);
			for(ll j=1;j<=n;j++){
				if(s[j]==2){
					sm++;
				}
			}
		}
		cout<<sm<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/