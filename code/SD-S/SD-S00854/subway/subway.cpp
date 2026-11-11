#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
int c,m,n,d,q,w[N],t[500][N],vis[N],ans=0x3f3f3f3f,x,y;
vector< pair<int,int> >e[N],mp[N];
void dfs1(int acc,int u,int ende,int dis){
	if(u==ende){
		if(dis<ans){
			ans=dis;
			x=acc;
			y=ende;
		}
		return;
	}
	vis[u]=1; 
	for(int i=0;i<mp[u].size();i++){
		int v=mp[u][i].first;
		if(vis[v]) continue;
		dfs1(acc,v,ende,dis+mp[u][i].second);
	}
}
int main(){
	
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[k];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[i][a[j]];
			e[a[j]].push_back(make_pair(i,t[i][a[j]]));
			vis[a[j]]++;
		}
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]>1){
			for(int j=0;j<e[i].size();j++){
				for(int k=0;k<e[i].size();k++){
					if(j==k) continue;
					mp[e[i][j].first].push_back(make_pair(e[i][k].first,e[i][j].second+e[i][k].second));
					mp[e[i][k].first].push_back(make_pair(e[i][j].first,e[i][j].second+e[i][k].second));
				}
			}
		}
	} 
	while(q){
		int l,r;
		cin>>l>>r;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<e[l].size();i++){
			for(int j=0;j<e[r].size();j++){
				dfs1(e[l][i].first,e[l][i].first,e[r][j].first,0);
			}
		}
		ans=ans+(w[l]+w[r]+t[x][l]+t[y][r]);
		cout<<ans<<'\n';
		q--;
	}
	return 0;
}
