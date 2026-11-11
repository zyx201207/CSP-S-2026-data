#include<bits/stdc++.h>
using namespace std;
int w[500010],k[550];
vector<pair<int,int> >nd[500010];
long long dis[550][550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int id,t;
			cin>>id>>t;
			nd[id].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++){
		int len=nd[i].size();
		for(int j=0;j<len;j++){
			for(int h=0;h<len;h++)if(j!=h){
				dis[nd[i][j].first][nd[i][h].first]=1ll*nd[i][j].second+1ll*nd[i][h].second;
			}
		}
	}
	for(int h=1;h<=n;h++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int l1=nd[x].size(),l2=nd[y].size();
		long long ans=1e18;
		for(int j=0;j<l1;j++){
			for(int h=0;h<l2;h++){
//				cout<<nd[x][j].first<<' '<<nd[y][h].first<<' '<<dis[nd[x][j].first][nd[y][h].first]<<'\n';
				ans=min(ans,1ll*w[x]+1ll*nd[x][j].second+1ll*w[y]+1ll*nd[y][h].second+dis[nd[x][j].first][nd[y][h].first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}