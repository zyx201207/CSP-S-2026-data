#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int i=(s);i<=(e);i++)
typedef unsigned long long ll;
const int M=5e5+10,N=505;
ll w[M];
ll dis[N][N];
vector<pair<int,int>> tline[M];
void floyd(int n){
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	//cout<<"here\n";
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	ll a,t;
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,m){
		tline[i].clear();
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		//printf("k=%d\n",k);
		rep(p,1,k){
			cin>>a>>t;
			//printf("a=%d,t=%d\n",a,t);
			for(int j=0;!tline[a].empty()&&j<tline[a].size();j++){
				//printf("a=%d,to=%d\n",a,tline[a][j].first);
				dis[i][tline[a][j].first]=min(dis[i][tline[a][j].first],t+tline[a][j].second);
				dis[tline[a][j].first][i]=min(dis[tline[a][j].first][i],t+tline[a][j].second);
				
			}
			tline[a].push_back(make_pair(i,t));
		}
	}
	//cout<<"here\n";
	floyd(n);
	ll x,y,ans;
	rep(i,1,q){
		cin>>x>>y;
		ans=0x3fffffffffff;
		rep(i,0,tline[x].size()-1){
			rep(j,0,tline[y].size()-1){
				if(tline[x][i].first==tline[y][j].first){
					ans=min((ll)tline[x][i].second+tline[y][j].second,ans);
					continue;
				}
				ans=min(ans,dis[tline[x][i].first][tline[y][j].first]+tline[x][i].second
				+tline[y][j].second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
		//cout<<"here\n";
	}
	return 0;
}