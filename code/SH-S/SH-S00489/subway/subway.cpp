#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//c,n,m,d,q，分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int w[500005];//无所谓,最后两端加一下就行 
vector<int> ds[500005];
vector<pair<long long,int>>dts[505];
bool dtcs[505];
bool ts[500005];
long long bfs(int start,int end){
	memset(dtcs,0,sizeof(dtcs));
	for(int i=1;i<=m;i++){
		ts[i]=false;
	}
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push({0ll,start});
	while(!pq.empty()){
		pair<long long,int> np=pq.top();
		if(np.second==end){
			return np.first;
		}
		for(int i:ds[np.second]){
			if(dtcs[i]==false){
				long long allneed=0;
				for(pair<long long,int> j:dts[i]){
					if(j.second==np.second){
						allneed=j.first;
						break;
					}
				}
				for(pair<long long,int> j:dts[i]){
					if(ts[j.second]==false){
						ts[j.second]=true;
						pq.push({np.first+j.first+allneed,j.second});
					}
				}
				dtcs[i]=true;
			}
		}
		pq.pop();
	}
	return -2147484646ll;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int ki;
		scanf("%d",&ki);
		for(int j=1;j<=ki;j++){
			int ai;long long ti;
			scanf("%d%lld",&ai,&ti);
			dts[i].push_back({ti,ai});
			ds[ai].push_back(i);
		}
	}
	while(q--){
		int starti,endi;
		scanf("%d%d",&starti,&endi);
		printf("%lld\n",bfs(starti,endi)+w[starti]+w[endi]);
	}
	return 0;
}
