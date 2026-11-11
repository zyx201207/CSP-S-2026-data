#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300007],dp[300007][33],ans;
bool vis[33];
vector<int>adj,adj1,clear;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		long long p=pow(2,31),d=31;
		for(p; p!=0; p/=2) {
			if(a[i]>=p) {
				a[i]-=p;
				dp[i][d]=1;
			}
			d--;
		}
		adj.push_back(i);
	}
	adj1=adj;
	int plg=31;
	while(plg>=0) {
		adj1=clear;
		for(int i=0; i<adj.size(); i++) {
			if(dp[adj[i]][plg]==1) {
				adj1.push_back(adj[i]);
			}
		}
		if(adj1.size()>=m) {
			vis[plg]=1;
			adj=adj1;
		}
		plg--;
	}
	long long p=pow(2,31);
	for(int i=31;i>=0;i--){
		if(vis[i]==1){
			ans+=p;
		}
		p/=2;
	}
	cout<<ans;
		return 0;
}
