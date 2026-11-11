#include<bits/stdc++.h>
#define int long long
using namespace std;

int test_id,m,n,d,q,ans;
bool flaga=1,flagb=1;
int w[50010];
int line[510][50010];
pair<int,int> plan[10010];
bool mark[50510];
vector<pair<int,int>> edge[50510];
int dis[50510][50510];
priority_queue<pair<int,int>> pq;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&test_id,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	int tmp;
	for(int i=1;i<=n;i++){
		scanf("%lld",&tmp);
		line[i][0]=tmp;
		if(tmp>2) flaga=0;
		int last;
		for(int j=1;j<=tmp*2;j++){
			scanf("%lld",&line[i][j]);
			if(j==2) last=line[i][j];
			else if(j%2==0&&line[i][j]!=last){
				flagb=0;
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&plan[i].first,&plan[i].second);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tmp;j+=2){
			edge[line[i][j]].push_back({line[i][j+1],i+m});
			edge[i+m].push_back({line[i][j+1],line[i][j]});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=q;i++){
		memset(mark,0,sizeof mark);
		while(!pq.empty()) pq.pop(); 
		if(dis[plan[i].first][plan[i].second]<0x3f3f3f3f){
			printf("%lld",dis[plan[i].first][plan[i].second]);
			continue;
		}
		pq.push({0,plan[i].first});
		auto k=pq.top();
		for(auto it:edge[k.second]){
			if(!mark[it.second]){
				mark[it.second]=1;
				dis[plan[i].first][it.second]=min(dis[plan[i].first][it.second],k.first+it.first);
			}
		}
		printf("%lld\n",dis[plan[i].first][plan[i].second]+w[plan[i].first]+w[plan[i].second]);
	}
	return 0;
}
//meow
