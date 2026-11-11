#include<bits/stdc++.h>
//以地铁为点求全源最短路 
using namespace std;
const int MAXN=5e5+9;
int c,n,m,d,q;
long long dis[509][509]; //地铁i到地铁j最短
struct node{
	long long x,t;
};
vector<node> ls[MAXN],mp[509]; 
long long w[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i ++)cin>>w[i];
	for(int i = 1;i <= n;i ++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j ++){
			int a,t;
			cin>>a>>t;
			ls[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			dis[i][j]=LLONG_MAX;
			dis[j][i]=LLONG_MAX;
		}
		dis[i][i]=0;
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 0;j < ls[i].size();j ++){
			for(int k = j + 1;k < ls[i].size();k ++){
				mp[ls[i][j].x].push_back({ls[i][k].x,ls[i][j].t+ls[i][k].t});
				mp[ls[i][k].x].push_back({ls[i][j].x,ls[i][j].t+ls[i][k].t});
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		bool vis[509]={};
		priority_queue<pair<long long,long long>,vector<pair<long long,long long> > > que;;
		que.push({0,i});
		while(!que.empty()){
			pair<long long,long long> tp=que.top();
			que.pop();
			if(vis[tp.second])continue;
			dis[i][tp.second]=tp.first;
			vis[tp.second]=1;
			for(int j = 0;j < mp[tp.second].size();j ++){
				if(!vis[mp[tp.second][j].x])
					que.push(make_pair(tp.first+mp[tp.second][j].t,mp[tp.second][j].x));
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=LLONG_MAX;
		for(int a=0;a<ls[x].size();a++){
			for(int b=0;b<ls[y].size();b++){
				ans=min(ans,1ll-1+w[x]+w[y]+ls[x][a].t+ls[y][b].t+dis[ls[x][a].x][ls[y][b].x]);
//				if(i==1&&w[x]+w[y]+ls[x][a].t+ls[y][b].t+dis[a][b]==22){
//					printf("%d %d %d %d %d\n",w[x],w[y],ls[x][a].t,ls[y][b].t,dis[a][b]);
//				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}  //fc subway.out subway7.ans
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
