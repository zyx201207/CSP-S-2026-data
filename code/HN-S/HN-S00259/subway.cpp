#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//
namespace solution{
	long long dis[505][505];
	int c,n,m,d,q;
	long long w[500005];
	vector<pair<int,long long>  > pass[500005];
	void main(){
		cin>>c>>n>>m>>d>>q;
		for(int i = 1;i<=m;i++){
			cin>>w[i];
		} 
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				dis[i][j] = 0x3f3f3f3f3f3f3f3f;
			}
			dis[i][i] = 0;
		}
		for(int i = 1;i<=n;i++){
			int k;
			cin>>k;
//			for(int j = 1;j<=m;j++) t[i][j] = 0x3f3f3f3f3f3f3f3f;
			for(int j = 1;j<=k;j++){
				int pos;
				long long t;
				cin>>pos;
				cin>>t;
//				for(auto &it:pass[pos]){
//					dis[i][it.first] = dis[it.first][i] = 
//					min(dis[i][it.first],t+it.second);
//				}
				pass[pos].push_back(make_pair(i,t));
//				cin>>t[i][pos];
			}
		}
		for(int i = 1;i<=m;i++){
			for(int j = 0;j<(int)pass[i].size();j++){
				for(int K = j+1;K<(int)pass[i].size();K++){
					const auto &it = pass[i][j];
					const auto &it2 = pass[i][K];
					dis[it.first][it2.first] = dis[it2.first][it.first] = 
					min(dis[it.first][it2.first],it.second+it2.second);
				}
			}
//			for(auto &it:pass[i]){
//				for(auto &it2:pass[i]){
//					dis[it.first][it2.first] = dis[it2.first][it.first] = 
//					min(dis[it.first][it2.first],it.second+it2.second);
//				}
//			} 
		}
//		for(int i = 1;i<=m;i++){
//			for(int j = 0;j<(int)pass[i].size();j++){
//				for(int k = 0;k<(int)pass[i].size();k++){
//					if(j==k) continue;
//					dis[pass[i][j]][pass[i][k]] = 
//					dis[pass[i][k]][pass[i][j]] = 
//					min(dis[pass[i][j]][pass[i][k]],
//					t[pass[i][j]][i]+t[pass[i][k]][i]);
//				}
//			}
//		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				if(dis[i][k]==0x3f3f3f3f3f3f3f3f) continue;
				for(int j = 1;j<=n;j++){
					if(dis[k][j]==0x3f3f3f3f3f3f3f3f) continue;
					dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int A,B;
			cin>>A>>B;
			long long ans = w[A]+w[B];
			long long minn = 0x3f3f3f3f3f3f3f3f;
			for(auto &it:pass[A]){
				for(auto &it2:pass[B]){
					minn = min(minn,dis[it.first][it2.first]+it.second+it2.second);
				}
			}
//			cout<<minn<<' ';
			cout<<ans+minn<<endl;
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}

