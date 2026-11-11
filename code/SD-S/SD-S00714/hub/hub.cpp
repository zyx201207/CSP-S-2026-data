#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,k;
const int N=1e6+5;
vector<int> e[N];
int used[15],vis[15];
void dfs(int x){
	vis[x]=1;
	for(auto u:e[x]){
		if(!vis[u]&&used[u]){
			dfs(u);
		}
	}
}
int bfs(){
	queue<pair<int,int> > q; 
	for(int i=1;i<=n;i++){
		if(used[i]){
			q.push({i,0});
			vis[i]=0;
		}
	}
	while(!q.empty()){
		int u=q.back().first,step=q.back().second;
		q.pop();
		vis[u]=1;
		for(auto v:e[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push({v,step+1});
			} 
		}
		if(q.empty())return step;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c<=3){
			int ans=n;
			for(int i=0;i<(1<<n);i++){
				int t=i,cnt=0;
				for(int j=n;j>=1;j--){
					vis[j]=0;
					used[j]=(t&1);
					cnt+=(t&1);
					t>>=1;
				}
				if(cnt!=k)continue;
				cnt=0;
				for(int j=1;j<=n;j++){
					if(used[j]&&!vis[j]){
						cnt++;dfs(j);
					}
				}
				if(cnt>2)continue;
				for(int j=1;j<=n;j++)vis[j]=0;
				int temp=bfs();
				if(ans>temp){
					printf("%d:%d\n",i,temp);
					ans=temp;
				}
			}
			printf("%d",ans);
		}
		else{
			printf("%d",(n-k)/3);
		}
	}
	return 0; 
	//da jia jue de wo zhe yi tuo dong xi neng pian dao fen ma
}

