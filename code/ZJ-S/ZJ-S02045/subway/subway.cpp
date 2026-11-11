#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int _,n,m,d,q,w[M];
ll g[N][N];
vector<pair<int,int>>stt[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,t;
			cin>>x>>t;
			stt[x].push_back(make_pair(i,t));		
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=(i==j?0:1e18);
	for(int i=1;i<=m;i++){
		for(int j=0;j<stt[i].size();j++){
			for(int k=j+1;k<stt[i].size();k++){
				int u=stt[i][j].first,v=stt[i][k].first;
				g[u][v]=g[v][u]=stt[i][j].second+stt[i][k].second;
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//	for(int i=1;i<=n;i++)
//		for(int j=i+1;j<=n;j++)
//			cout<<"edge"<<i<<' '<<j<<' '<<g[i][j]<<endl;
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res=1e18;
		for(auto linex:stt[x]){
			for(auto liney:stt[y]){
				res=min(res,g[linex.first][liney.first]+linex.second+liney.second);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
