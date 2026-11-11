#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,k,a[1000005];
int p[1000005];
vector<int> e[1000005];
int fa[1000005];
int choice[1000005];
int d[1005][1005];
int fx[1000005];
int cvis[1000005];
int mi=INT_MAX;
void dfs1(int fa,int x){
	for(auto u: e[x]){
		if(fx[u]==1&&u!=fa){
			dfs1(x,u);
			cvis[u]++;
		}
	}
	return;
}
bool check(vector<int> x){
	int t=x[0];
	memset(fx,0,sizeof(fx));
	memset(cvis,0,sizeof(cvis));
	for(int i=1;i<x.size();i++){
		fx[x[i]]=1;
	}
	cvis[x[0]]=1;
	dfs1(0,x[0]);
	for(int i=0;i<x.size();i++){
		if(cvis[x[i]]==0)return false;
	}
	return true;
}
void floyd(){
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][l]+d[l][j]){
					d[i][j]=d[i][l]+d[l][j];
				}
			}
		}
	}
}
void dfs(int x){
	if(x==k+1){
		vector<int> cse;
		for(int i=1;i<=k;i++)cse.push_back(choice[i]);
		if(!check(cse))return;
		int ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=0;j<k;j++){
				ma=max(ma,d[i][cse[j]]);
			}
		}
		mi=min(mi,ma);
		return;
	}
	for(int i=1;i<=n;i++){
		choice[x]=i;
		dfs(x+1);
	}
}
void solve(){
	cin>>n>>k;
	memset(d,0xff,sizeof(d));
for(int i=1;i<n;i++){
	int u,v;
	cin>>u>>v;
	e[u].push_back(v);
	e[v].push_back(u);
	d[u][v]=1;
	d[v][u]=1;
}
	dfs(1);
	cout<<mi<<endl;
	mi=INT_MAX;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}// CSP-S 2026 RP++
