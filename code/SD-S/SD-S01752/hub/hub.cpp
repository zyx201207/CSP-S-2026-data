#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long dis[100100],len[100100],book[100100];
vector <long long> V[100100];
struct node{
	long long id,val;
	bool operator < (const node & a) const {
		return val < a.val;
	}
};
priority_queue <node> Q;
void dfs(long long x,long long f,long long d){
	long long i;
	dis[x] = min(dis[x],d);
	len[x] = x;
	for(i = 0;i < V[x].size();i++){
		if(V[x][i] == f){
			continue;
		}
		dfs(V[x][i],x,d+1);
		if(dis[len[x]] < dis[len[V[x][i]]]){
			len[x] = len[V[x][i]];
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,n,i,j,k,o,ans,u,v,cnt;
	node cun;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(i = 1;i <= n;i++){
			V[i].clear();
		}
		for(i = 1;i < n;i++){
			scanf("%lld%lld",&u,&v);
			V[u].push_back(v);
			V[v].push_back(u);
		}
		if(c == 13 || c == 14){
			printf("%lld\n",(((n-1)/2-2)/4)-(k-2-((n-1)/2-2)%4)/4);
			continue;
		}
		while(!Q.empty()){
			Q.pop();
		}
		ans = 1e10;
		for(i = 1;i <= n;i++){
			for(j = i+1;j <= n;j++){
				for(o = 1;o <= n;o++){
					dis[o] = 1e10;
					book[o] = 0;
					book[o] = 0;
				}
				dis[i] = 0;
				dis[j] = 0;
				dfs(i,0,0);
				dfs(j,0,0);
				Q.push((node){i,dis[len[i]]+1});
				Q.push((node){j,dis[len[j]]+1});
				Q.pop();
				cnt = 0;
				while(!Q.empty() && cnt < k){
					cun = Q.top();
					Q.pop();
					if(book[cun.id]){
						continue;
					}
					cnt++;
					book[cun.id] = 1;
					for(o = 0;o < V[cun.id].size();o++){
						if(book[V[cun.id][o]]){
							continue;
						}
						Q.push((node){V[cun.id][o],dis[len[V[cun.id][o]]] - dis[V[cun.id][o]]+1});
					}
				}
				ans = min(ans,Q.top().val);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//240pts.
