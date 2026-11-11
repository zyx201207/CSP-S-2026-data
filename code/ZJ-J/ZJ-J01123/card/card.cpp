#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100];
int used[300100];
int dp[300100];
vector<int> g;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof used);
		g.clear();
		int k=0;
		for(int j=i;j<=n;j++){
			if(used[a[j]]){
				while(g[g.size()-1]!=a[j]){
					used[g[g.size()-1]]=0;
					g.pop_back();
				}
				g.pop_back();
			}
			g.push_back(a[j]);
			used[a[j]]=1;
		}
		for(int j=0;j<g.size();j++){
			dp[g[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
}