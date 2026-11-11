#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int c,n,m,d,Q;
int w[maxn];
vector<int> L[maxn];
int t[505][maxn];
struct node{
	int to;
	long long len;
};
vector<node> line[505];
long long dis[505];
struct Node{
	long long dis;
	int tar;
	friend bool operator <(Node a,Node b){
		return a.dis>b.dis;
	}
};
priority_queue<Node> q;
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			t[i][x]=y;
			L[x].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		int e=L[i].size();
		for(int j=0;j<e-1;j++){
			for(int k=j+1;k<e;k++){
				int a=L[i][j],b=L[i][k];
				line[a].push_back({b,1ll*(t[a][i]+t[b][i])});
				line[b].push_back({a,1ll*(t[a][i]+t[b][i])});
			}
		}
	}
	for(int i=1;i<=n;i++){
		memset(dis,0x3f,sizeof(dis));
		dis[i]=0;
		q.push({dis[i],i});
		while(!q.empty()){
			Node tmp=q.top();
			q.pop();
			int now=tmp.tar;
			if(dis[now]!=tmp.dis) continue;
			for(int i=0;i<line[now].size();i++){
				int to=line[now][i].to;
				if(dis[to]>dis[now]+line[now][i].len){
					dis[to]=dis[now]+line[now][i].len;
					q.push({dis[to],to});
				}
			}
		}
		for(int j=1;j<=n;j++) f[i][j]=dis[j];
		
	}
	/*
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		int e=L[i].size();
		for(int j=0;j<e-1;j++){
			for(int k=j+1;k<e;k++){
				int a=L[i][j],b=L[i][k];
				f[b][a]=f[a][b]=1ll*(t[a][i]+t[b][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	*/
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e18;
		for(int i=0;i<L[x].size();i++){
			for(int j=0;j<L[y].size();j++){
				ans=min(ans,f[L[x][i]][L[y][j]]+t[L[x][i]][x]+t[L[y][j]][y]);
			}
		}
		ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
