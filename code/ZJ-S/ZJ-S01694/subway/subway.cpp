#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
#define LL long long
using namespace std;
const int inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;
const int tianyiblue=0x66ccff;
int cid,n,m,d,q,a[500005],dis[505][505];
vector<PII>vec[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		while(k--){
			int id,val;cin>>id>>val;
			vec[id].push_back({i,val});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i!=j)dis[i][j]=INF;
			else dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;++i){
		int len=vec[i].size();
		for(int xid=0;xid<len;++xid){
			for(int yid=xid+1;yid<len;++yid){
				PII x=vec[i][xid],y=vec[i][yid];
				dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
				dis[y.first][x.first]=min(dis[y.first][x.first],x.second+y.second);
			}
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,res=0,ans=INF;
		cin>>x>>y,res=a[x]+a[y];
		int lenx=vec[x].size(),leny=vec[y].size();
		for(int i=0;i<lenx;++i){
			for(int j=0;j<leny;++j){
				PII px=vec[x][i],py=vec[y][j];
				ans=min(ans,px.second+py.second+res+dis[px.first][py.first]);
			}
		}cout<<ans<<'\n';
	}
	return 0;
}

