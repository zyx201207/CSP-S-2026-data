#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+3);
	vector<vector<array<ll,2>>> haha(m+3);
	vector<vector<ll>> ans(n+3,vector<ll>(n+3,1e18));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n&&cin>>k;i++)
		for(ll j=1,a,t;j<=k&&cin>>a>>t;j++)
			haha[a].push_back({i,t});
	for(int i=1;i<=m;i++){
		vector<array<ll,2>> &ha=haha[i];
		for(int j=0,s=ha.size();j<s;j++)
			for(int l=j+1;l<s;l++)
				ans[ha[j][0]][ha[l][0]]=ha[j][1]+ha[l][1],
				ans[ha[l][0]][ha[j][0]]=ha[j][1]+ha[l][1];
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(j==k) continue;
				ans[i][j]=((i==j)?0:min(ans[i][j],ans[i][k]+ans[k][j]));
			}
		}
	for(int i=1,x,y;i<=q&&cin>>x>>y;i++){
		ll answer=1e18;
		for(array<ll,2> u:haha[x])
			for(array<ll,2> v:haha[y]){
				answer=min(answer,ans[u[0]][v[0]]+u[1]+v[1]);
			}
		cout<<answer+w[x]+w[y]<<"\n";
	}
	
	
	return 0;
}