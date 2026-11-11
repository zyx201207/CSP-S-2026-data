#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500001,M=501;
int ID,T,n,m,D,c[N],k[M],g[N];
bool d[N];
ll f[M][M],b[M][M];
vector<pair<int,int>> a[N],e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	memset(f,127,sizeof(f));
//	memset(b,127,sizeof(b));
	scanf("%d%d%d%d%d",&ID,&m,&n,&D,&T);
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back({x,y});
			e[x].push_back({i,y});
		}
	}
	for(int i=0;i<=m;i++)
	for(int j=0;j<=m;j++)
	b[i][j]=1e18;
	for(int i=0;i<=m;i++)
	b[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto j:a[i]){
			for(auto k:e[j.first]){
//				printf("%lld %d %d\n",b[i][k.first],j.second,k.second);
				b[i][k.first]=min(b[i][k.first],1LL*j.second+k.second);
			}
		}
	}
//	printf("%lld\n",b[1][3]);
	for(int k=1;k<=m;k++)
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	b[i][j]=b[j][i]=min({b[j][i],b[i][j],b[i][k]+b[k][j]});
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++)
//		printf("%lld ",b[i][j]);
//		puts("");
//	}
	while(T--){
		ll ans=1e18;
		int x,y;
		scanf("%d%d",&x,&y);
		for(auto i:e[x])
		for(auto j:e[y])
		ans=min(ans,1LL*c[x]+i.second+1LL*c[y]+j.second+b[i.first][j.first]);
		printf("%lld\n",ans);
	}
//	memset(g,127,sizeof(g));
//	priority_queue<pair<int,int>> q;
//	q.push({0,1});
//	while(!q.empty()){
//		int x=q.front().second,y=q.front().first;
//		q.pop();
//		d[x]=1;
//		for(int i=1;i<=m;i++)
//		if(y+g[x]<g[i]){
//			b[i][j]=y+g[x]
//		}
//	}
//	while(T--){
//		memset(d,0,sizeof(d));
//		memset(f,127,sizeof(f));
//		queue<int> q;
//		int s,t;
//		scanf("%d%d",&s,&t);
//		for(auto i:e[s])
//		f[i.first]=i.second,q.push(i.first),d[i.first]=1;;
//		while(!q.empty()){
//			int x=q.front().first;
//			int y=q.front().sec
//		}
//	}
	return 0;
}
