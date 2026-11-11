#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static ll c,n,m,d,q;//测试点，线路数，站点数，最大线路数，询问数 
static vector<pair<ll,ll>> bian[510];
//理解成每个线路是1个节点，然后连边的时候取出发和结束的节点。边权是经过站厅需要的时间。最多400种（因为每个站只有20条） 
static ll tm1[500010];
static vector<pair<ll,ll>> zhan[510];//record every line and time
static vector<pair<ll,ll>> zd[500010];//<哪些线，进入站台要多久> 
static ll dis[510][510];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				dis[i][j]=0;continue;
			}
			dis[i][j]=114514191981054188LL;
		}	
	}
	for(int i=1;i<=m;i++){
		cin>>tm1[i];//record time
	}
	for(int j=1;j<=n;j++){
		ll tmp,a,t;
		cin>>tmp;//the line station nunber
		for(int i=1;i<=tmp;i++){
			cin>>a>>t;
			zhan[j].push_back(make_pair(a,t));//记录这个线路的站点。 
			for(auto k:zd[a]){//建边
				ll xian=k.first,shi=k.second;
				ll quan=shi+t;//上去1次，下来1次 
				dis[j][xian]=min(dis[j][xian],quan); 
				dis[xian][j]=min(dis[j][xian],quan); 
			}
			zd[a].push_back(make_pair(j,t));//记录这个站点的线路。 
		}
	}
	//跑最短路 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int k=1;k<=n;k++){
				 dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	ll x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ll ans=114514191981054188LL;
		ll iot=tm1[x]+tm1[y];//进站出站时间。 
		for(auto j:zd[x]){
			for(auto k:zd[y]){
				ans=min(ans,dis[j.first][k.first]+j.second+k.second);
			}
		}
		cout<<ans+iot<<'\n';
	}
	return 0;
}
