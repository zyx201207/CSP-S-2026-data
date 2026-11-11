#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace zhu{bool ST;
int c,n,m,d,q,mp[550][550],W[500500];
vector<pair<int,int>> ve[500500];
bool ED;string main(){
	memset(mp,0x3f,sizeof mp);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		mp[i][i]=0;
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			ve[x].push_back({y,i});
		}
	}
	for(int i=1;i<=m;i++){
		int sz=ve[i].size();
		for(int j=0;j<sz;j++){
			for(int k=0;k<j;k++){
				int u=ve[i][j].second,v=ve[i][k].second;
				int w=ve[i][j].first+ve[i][k].first;
				mp[u][v]=min(mp[u][v],w);
				mp[v][u]=min(mp[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(auto j:ve[x]){
			for(auto k:ve[y]){
				ans=min(ans,mp[j.second][k.second]+j.first+k.first);
			}
		}
		cout<<ans+W[x]+W[y]<<'\n';
	}
	return ".";
}
}
signed main(){
//	system("fc subway.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<(&zhu::ST-&zhu::ED)/1048576.0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
