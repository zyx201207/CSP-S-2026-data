#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,t;
};
bool flag = 1;
int c,n,m,d,q;
int w[500005];
vector<node>a[500515];
long long s[500515];
int t1;
bool vis[500515];
void BFS_CSPshicj(int sr,int er){
	queue<pair<long long,int>>pq;
	for(int i = 1;i<=m+500;i++)vis[i] = 0;
	s[sr] = 0;
	pq.push({0,sr});
	while(!pq.empty()){
		auto k = pq.front();
		int u = k.second;
		pq.pop();
		for(auto v:a[u]){
			if(vis[v.u]==1){
				continue;
			}
			pq.push({k.first+t1,v.u});
			if(v.u==er){
				printf("%lld\n",k.first+t1+w[sr]+w[er]);
				return ;
			}
			vis[v.u] = 1;
		}
	}
	
}
void CJDL(int sr,int er){
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >pq;
	s[sr] = 0;
	pq.push({0,sr});
	while(!pq.empty()){
		auto k = pq.top();
		int u = k.second;
		pq.pop();
		for(auto v:a[u]){
			if(s[v.u]>s[u]+v.t){
				s[v.u] = min(s[v.u],s[u]+v.t);
				pq.push({s[v.u],v.u});
			}
		}
	}
	printf("%lld\n",s[er]+w[sr]+w[er]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i<=m;i++){
		scanf("%d",&w[i+500]);
	}
	for(int i = 1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j = 1,u,t;j<=k;j++){
			scanf("%d",&u);
			scanf("%d",&t);
			if(t1!=t&&t1!=0){
				flag = 0;
			}
			t1 = t;
			a[i].push_back({u+500,t});
			a[u+500].push_back({i,t});
		}
	}
	if(flag){
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			BFS_CSPshicj(x+500,y+500);
		}
	}
	else{
		while(q--){
			int x,y;
			for(int i = 1;i<=m+500;i++){
				s[i] = 1e18;
			}
			scanf("%d%d",&x,&y);
			CJDL(x+500,y+500);
		}	
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 4 2 4 4 4
//3 2 4 3 4 5 4
//1 3
//1 2
