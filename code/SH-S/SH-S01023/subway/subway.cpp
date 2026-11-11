#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,n,m,D,Q,w[500010],dis[510][510];
vector<pair<int,int> >cost[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int K;
		cin>>K;
		for(int j=1;j<=K;j++){
			int id,val;
			cin>>id>>val;
			cost[id].push_back({i,val});
		}
	} 
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<cost[i].size();j++){
			for(int k=j+1;k<cost[i].size();k++){
				pair<int,int>tmp1=cost[i][j],tmp2=cost[i][k];
				if(dis[tmp1.first][tmp2.first]>tmp1.second+tmp2.second)
					dis[tmp1.first][tmp2.first]=tmp1.second+tmp2.second;
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],min(dis[k][i],dis[i][k])+min(dis[j][k],dis[k][j]));
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int ans=1000000000000000000;
		for(int i=0;i<cost[x].size();i++){
			for(int j=0;j<cost[y].size();j++){
				ans=min(ans,w[x]+w[y]+dis[cost[x][i].first][cost[y][j].first]+cost[x][i].second+cost[y][j].second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 


/*
我们在干些什么
路径可以被拆分为从x号地铁站总到对应站厅的耗时以及y号地铁站走到站厅的耗时
然后枚举一下对应的起点站台和终点站台，得到站台间最小的耗时(qd^2)
站台间的边等价于从一个公共点走，这个可以给它们合并起来跑floyd(对于一个公共点，最多只有d^2次枚举)
然后就做完了-3:05 



疑似过了  3:18 

*/
