#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxN=5e5+5;
int c,n,m,d,T;
int tim[kMaxN];
int k[kMaxN];
vector<int>a[505];
vector<int>t[505];
struct node{
	int id;
	int time;
};
vector<node>D[kMaxN];
int f[505][505];
vector<node>home[kMaxN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>tim[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,time;
			cin>>x>>time;
			a[i].push_back(x);
			t[i].push_back(time);
			D[x].push_back({i,time});
			home[x].push_back({i,j-1});
		}
	}
	for(int i=1;i<=m;i++){
		if(D[i].size()<2)continue;
		for(int j=0;j<D[i].size();j++){
			for(int k=0;k<D[i].size();k++){
				int id1=D[i][j].id;
				int id2=D[i][k].id;
				int time1=D[i][j].time;
				int time2=D[i][k].time;
				f[id1][id2]=f[id2][id1]=min(f[id1][id2],time1+time2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(T--){
		int x,y,minn=INT_MAX;
		cin>>x>>y;
		for(int i=0;i<home[x].size();i++){
			for(int j=0;j<home[y].size();j++){
				int tmp=f[home[x][i].id][home[y][j].id]+tim[x]+tim[y]+t[home[x][i].id][home[x][i].time]+t[home[y][j].id][home[y][j].time];
				minn=min(minn,tmp);
			}
		}
		cout<<minn<<'\n';
	}
	return 0;
}
