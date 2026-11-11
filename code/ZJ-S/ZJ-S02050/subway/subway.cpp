#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
//g=gate h=hall p=platform s=subway
struct station{
	int gh;
	vector<pair<int,int> > sub;//line,h2s;
};
station st[500010];
int graphset[510][510];
struct edge{
	int a,b;
	int len;
};
vector<edge> graph;
int dis[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(graphset,0x3f,sizeof(graphset));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>st[i].gh;
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=0;j<ki;j++){
			int a,t;
			cin>>a>>t;
			st[a].sub.push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int p=0;p<st[i].sub.size();p++){
			for(int q=p+1;q<st[i].sub.size();q++){
				graphset[st[i].sub[p].first][st[i].sub[q].first]=min(
					graphset[st[i].sub[p].first][st[i].sub[q].first],
					st[i].sub[p].second+st[i].sub[q].second
					);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(graphset[i][j]!=inf){
				graph.push_back({i,j,graphset[i][j]});
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(auto t:graph){
				if(dis[i][j]>dis[i][t.a]+t.len+dis[t.b][j]){
					dis[i][j]=dis[i][t.a]+t.len+dis[t.b][j];
				}
				if(dis[i][j]>dis[i][t.b]+t.len+dis[t.a][j]){
					dis[i][j]=dis[i][t.b]+t.len+dis[t.a][j];
				}
			}
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		int mi=inf;
		for(auto i:st[xr].sub){
			for(auto j:st[yr].sub){
				mi=min(mi,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<mi+st[xr].gh+st[yr].gh<<"\n";
	}
	return 0;
}