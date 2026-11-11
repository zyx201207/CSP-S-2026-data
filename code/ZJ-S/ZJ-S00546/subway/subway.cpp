#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
typedef long long ll;
const int N=505,M=1e5+5,Q=1e5+5,D=25;
struct node{
	int stn,ln;
	int stl;
	int edl;
};
int c,n,m,d,q;
int w[M];
int k[N],a[N][M],t[N][M];
int x[Q],y[Q];
int b[N][M];
bool vis[M];
pair<ll,pair<bool,bool>> dis[D][D][M];
vector<int> vec[M];
int main(){
	//目前来看能过 1 ~ 6 的测试点qwq ，再多就要RE了 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	//w[x]表示每个地铁站口到站厅的时间 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		//k[x]表示第x条线路的站点数量 
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			//a[x][y]表示第x条线路的第y站的id
			b[i][a[i][j]]=j;
			//b[x][y]表示第x条线路上id为y的站的序号 
			//t[x][y]表示第x条线路的第y站走到站厅的时间 
			vec[a[i][j]].push_back(i);
			//vec[x]表示站点x的所有线路 
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++) for(auto it:vec[x[i]]) for(auto its:vec[y[i]]) dis[it][its][j]={INF,{1,0}};//最开始坐线路it，最后从线路it2下车，从第x[i]站到第j站初始设为INF
		for(auto it:vec[x[i]]) for(auto its:vec[y[i]]) dis[it][its][x[i]]={0,{1,0}};//自己走到自己是0
		queue<node> q;//q表示站点id、线路id、起始线路及最终线路 
		for(auto it:vec[x[i]]) for(auto its:vec[y[i]]) q.push({x[i],it,it,its});
		while(!q.empty()){
			auto u=q.front();
			int stn=u.stn;//站点 
			int ln=u.ln;//线路
			int stl=u.stl;
			int edl=u.edl;
			q.pop();
			int len=vec[stn].size(); 
			for(int j=0;j<len;j++){//遍历每条线路
				for(int l=1;l<=k[vec[stn][j]];l++){//遍历每一站
					int newln=vec[stn][j];
					int newstn=a[newln][l];
					int ID=b[ln][stn];//线路ln的第stn站的编号 
					int newID=b[newln][stn];//线路newln的第stn站的编号
					if(newln==ln){
						if(dis[stl][edl][newstn].first>dis[stl][edl][stn].first){
							dis[stl][edl][newstn].first=dis[stl][edl][stn].first;
							if(ln==stl) dis[stl][edl][newstn].second.first=1;
							if(ln==edl) dis[stl][edl][newstn].second.second=1;
							q.push({newstn,newln,stl,edl});
						}
					}
					else{
						if(dis[stl][edl][newstn].first>dis[stl][edl][stn].first+t[ln][ID]+t[newln][newID]){
							dis[stl][edl][newstn].first=dis[stl][edl][stn].first+t[ln][ID]+t[newln][newID];
							if(newln==stl) dis[stl][edl][newstn].second.first=1;
							if(newln==edl) dis[stl][edl][newstn].second.second=1;
							q.push({newstn,newln,stl,edl});
						}
					}
//					cerr<<newln<<' '<<newstn<<' '<<ID<<' '<<newID<<'\n';
				}
			}
		}
//		for(int i=1;i<=m;i++){
//			cout<<i<<" : ";
//			for(auto it:vec[i]){
//				cout<<it<<',';
//			}
//			cout<<'\n';
//		}
//		cout<<'\n';
//		cout<<dis[1][2][y[i]]<<','<<w[x[i]]<<','<<w[y[i]]<<'\n';
		ll res=INF;
		for(auto it:vec[x[i]]){
			for(auto its:vec[y[i]]){
				ll stID=b[it][x[i]];
				ll edID=b[its][y[i]];
				ll Into=w[x[i]]+w[y[i]];
				if(dis[it][its][y[i]].second.first&dis[it][its][y[i]].second.second) res=min(res,1LL*(dis[it][its][y[i]].first+Into+t[it][stID]+t[its][edID]));
//				cerr<<it<<'-'<<its<<':'<<dis[it][its][y[i]].second.first<<','<<dis[it][its][y[i]].second.second<<','<<Into<<','<<t[it][stID]<<','<<t[its][edID]<<'\n';
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
