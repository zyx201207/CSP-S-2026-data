#include <bits/stdc++.h>
using namespace std;
const int MaxN = 6e3+100;
const int INF = 1e9+7;
int TESTID;
long long d,n;
long long pos[MaxN];
vector<int> mp[MaxN];
int dist[MaxN][MaxN];
bool vis[MaxN];
int cnt[MaxN][MaxN];
struct Node{
	int v,w;
	bool operator<(const Node&other)const{return w>other.w;}
};
void dijkstra(int start){
	for(int i = 0; i <= n; i++)vis[i]=false;
	for(int i = 0; i <= n; i++)dist[start][i]=INF;
	priority_queue<Node,vector<Node>,less<Node>> pq;
	pq.push({start,0});
	dist[start][start]=0;
	cnt[start][start]=1;
	while(!pq.empty()){
		int u = pq.top().v;pq.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int v: mp[u]){
			int w = 1;
//			printf("dist[%d][%d]=%d,dist[%d][%d]=%d\n",start,u,dist[start][u],start,v,dist[start][v]); 
			if(dist[start][v]==dist[start][u]+w){
//				printf("WONDERFUL\n");
//				printf("let cnt[%d][%d](%d)  plus %d\n",start,v,cnt[start][v] ,cnt[start][u]);
				cnt[start][v] += cnt[start][u];
//				pq.push({v,dist[start][v]});
			}
			if(dist[start][v]>dist[start][u]+w){
				dist[start][v] = dist[start][u] + w;
//				printf("let cnt[%d][%d](%d)  =s %d\n",start,v,cnt[start][v] ,cnt[start][u]);
				pq.push({v,dist[start][v]});
				cnt[start][v] = cnt[start][u];
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>TESTID>>T;
//	if(TESTID==12||TESTID==11)
	while(T--){
		cin>>n>>d;
		for(int i = 0; i <= n; i++){
			mp[i].clear();
			for(int j = 0; j <= n; j++){
				cnt[i][j]=0;
			}
		}
		for(int i = 1; i <= n; i++)cin>>pos[i];
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(pos[j]-pos[i]<=d){
					mp[i].push_back(j);
				}
			}
		}
//		for(int i =1 ; i <= n; i++){
//			cout<< i << ":";
//			for(int v: mp[i])cout<<v << ' ';
//			cout << '\n';
//		} 
		for(int i = 1; i <= n; i++){
			dijkstra(i);
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
//				printf("cnt[%d][%d]=%d\n",i,j,cnt[i][j]);
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
