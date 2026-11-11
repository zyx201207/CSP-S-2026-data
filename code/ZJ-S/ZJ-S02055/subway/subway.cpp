#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0,l,r,k;
bool s[510];
long long w[500010],ap[510][510];
vector< pair<int,long long> >a[510];
bool cmp(pair<int,long long> x,pair<int,long long> y){
	return x.second<y.second;
} 
void dfs(int x,int z,int y,long long wp){
	ap[z][y]=min(ap[z][y],wp);
	s[x]=1;
	for(int i=0;i<a[x].size();i++){
		if(s[a[x][i].first]==0){
			dfs(a[x][i].first,z,y,wp+a[x][i].second);
			return;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) ap[i][j]=0;
			else ap[i][j]=2000000000;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int u;
		long long w;
		for(int j=1;j<=k;j++){
			cin>>u>>w;
			a[i].push_back({u,w});
			a[u].push_back({i,w});
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		dfs(l,l,r,0);
		cout<<ap[l][r]<<'\n';
	}
	return 0;
}

