#include<fstream>
#include<cstring>
#include<vector>
#define st first
#define nd second
using pii=std::pair<int,long long>;
constexpr int N{510},M{500010};
int c,n,m,d,q;
long long dis[N][N];
long long w[M];
std::vector<pii>mp[M]; 
std::ifstream cin("subway.in");
std::ofstream cout("subway.out");
void solve(){
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i{1};i<=m;++i)cin>>w[i];
	for(int i{1},k;i<=n;++i){
		dis[i][i]=0;
		cin >> k;
		for(int j{1},x,y;j<=k;++j)cin>>x>>y,mp[x].push_back({i,y}); 
	}
	for(int i{1};i<=m;++i){
		for(pii& u:mp[i])for(pii& v:mp[i]){
			if(u==v)continue;
			dis[u.st][v.st] = std::min(dis[u.st][v.st],u.nd+v.nd);
		}
	}
	for(int k{1};k<=n;++k){
		for(int i{1};i<=n;++i)for(int j{1};j<=n;++j)
		dis[i][j] = std::min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int x,y;q--;){
		long long min{9223372036854775807};
		cin>>x>>y;
		for(pii& i:mp[x]){
			for(pii& j:mp[y]){
				min=std::min(dis[i.st][j.st]+i.nd+j.nd,min);
			}
		}
		cout << min+w[x]+w[y]<<'\n';
	}
}
signed main(){
	solve();
	cin.close();
	cout.close();
	return 0;
} 
