#include<bits/stdc++.h>
using namespace std;
const int N=505,K=5E5+5;
int IIID,n,m,d,q;
vector<pair<int,int>> v[N],e[K];
long long dis[N][N];
int w[K];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>IIID>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;cin>>ki;
		v[i].reserve(ki);
		for(int j=1;j<=ki;j++){
			int a,t;cin>>a>>t;
			e[a].push_back({i,t});
			v[i].push_back({a,t});
		}
		for(int j=1;j<=n;j++){
			dis[i][j]=LLONG_MAX/4;
		}
		dis[i][i]=0;
		sort(v[i].begin(),v[i].end());
	}
	for(int x=1;x<=n;x++){
		for(int y=x+1;y<=n;y++){
			long long dd=LLONG_MAX;
			for(int i=0,j=0;i<v[x].size()&&j<=v[y].size();i++){
				while(j<=v[y].size()&&
				v[x][i].first>v[y][j].first)j++;
				if(v[x][i].first==v[y][j].first){
					dd=min(dd,(long long)v[x][i].second+v[y][j].second);
				}
			}
			dis[x][y]=min(dis[x][y],dd);
			dis[y][x]=min(dis[y][x],dd);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],
				dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int QQ=1;QQ<=q;QQ++){
		int x,y;cin>>x>>y;
		long long ans=LLONG_MAX;
		for(pair<int,int> i:e[x]){
			for(pair<int,int> j:e[y]){
				ans=min(ans,dis[i.first][j.first]
				+i.second+j.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

