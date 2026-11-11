#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d;
ll x[2100000];
vector<int>edges[2100000];
ll dist[2100000];
ll bfs(int s,int t){
	for(int i = 1;i <= n;i++){
		dist[i] = -1;
	}
	dist[s] = 0;
	queue<int>q;
	q.push(s);
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : edges[u]){
			if(v == t && (dist[u] + 1 == dist[v] || dist[v] == -1)){
				cnt++;
//				printf("from %d to end %d:Success!\n",u,v);
			}
//			printf("from %d to %d:Success! dist[u] = %d\n",u,v,dist[u]);
			if(dist[v] != -1) continue;
			q.push(v);
			dist[v] = dist[u] + 1;
		}
	}
	return cnt;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
			for(int j = 1;j < i;j++){
				if(abs(x[i] - x[j]) <= d){
					edges[i].push_back(j);
					edges[j].push_back(i);
//					printf("linked %d -> %d\n",i,j);
				}
			}
		}
		int ans = 0;
		for(int u = 1;u <= n;u++){
			for(int v = u + 1;v <= n;v++){
				if(bfs(u,v) == 2){
					ans++;
//					printf("Node %d => %d:Success!\n",u,v);
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

