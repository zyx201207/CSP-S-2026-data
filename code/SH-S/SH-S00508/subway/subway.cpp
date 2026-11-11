#include<algorithm>
#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
using namespace std;
long long conn[550][550];
long long dis[600000];
vector<pair<int,long long>> name[600000];
int c,n,m,d,q;
constexpr long long inf = 1e18;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i!=j) conn[i][j]=inf;
		}
	}
	for(int i = 1;i <= m;i++){
		cin>>dis[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			int a;
			long long x;
			cin>>a>>x;
			name[a].push_back({i,x});
		}
	}
	for(int i = 1;i <= m;i++){
		for(auto x : name[i]){
			for(auto y : name[i]){
				conn[x.first][y.first]=min(conn[x.first][y.first],x.second+y.second);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				conn[i][j]=min(conn[i][j],conn[i][k]+conn[k][j]);
			}
		}
	}
	for(int i = 1;i <= q;i++){
		int s,t;
		cin>>s>>t;
		long long ans = inf;
		for(auto x:name[s]){
			for(auto y:name[t]){
				ans = min(ans,x.second+y.second+conn[x.first][y.first]);
			}
		}
		cout<<ans+dis[s]+dis[t]<<'\n';
	}
	return 0;
}
