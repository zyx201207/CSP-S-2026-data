#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int ww[500010];
struct subway{
	int id,t;
};
bool operator<(subway a,subway b){
	return a.t>b.t;
}
vector<subway>way[510];
vector<int>sta[500010];
int f[500010];
int dis[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&ww[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int id,t;
			scanf("%d%d",&id,&t);
			way[i].push_back({id,t});
			sta[id].push_back({i});
		}
	}
	while(q--){
		int s,e;
		scanf("%d%d",&s,&e);
		memset(f,0,sizeof f);
		memset(dis,0x3f,sizeof dis);
		dis[s]=0;
		priority_queue<subway>qu;
		qu.push({s,0});
		int flag=0;
		while(qu.size()){
			subway t=qu.top();
			qu.pop();
			int id=t.id,w=t.t;
//			printf("!%d\n",id);
			if(f[id]){
				break;
			}
			f[id]=1;
			if(id==e){
				flag=1;
				printf("%d\n",w+ww[s]+ww[e]);
				break;
			}
			for(int i=0;i<sta[id].size();i++){
				int dt=sta[id][i];
				int xh=0;
				for(int j=0;j<way[dt].size();j++){
					if(way[dt][j].id==id){
						xh=way[dt][j].t;
						break;
					}
				}
				for(int j=0;j<way[dt].size();j++){
					if(way[dt][j].id!=id){
						if(w+way[dt][j].t+xh<dis[way[dt][j].id]){
//							if(way[dt][j].id==2||way[dt][j].id==3){
//								printf("!%d %d %d\n",way[dt][j].id,id,dis[way[dt][j].id]);
//							}
//							printf("!%d\n",way[dt][j].id);
//							if(way[dt][j].id==131){
//								printf("!%d %d\n",dis[way[dt][j].id],w+way[dt][j].t+xh);
//							}
							dis[way[dt][j].id]=w+way[dt][j].t+xh;
							qu.push({way[dt][j].id,dis[way[dt][j].id]});
							
						}
					}
				}
			}
		}
		if(!flag){
			printf("%d\n",dis[e]+ww[s]+ww[e]);
		}
	}
	return 0;
} 
//It's too difficult to solve
//I had AFOed for a year
//Now I'm a flashman in senior high school
//But...I lost the feeling of coding...
