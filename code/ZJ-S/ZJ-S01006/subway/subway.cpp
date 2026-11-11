#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
long long w[M],f[N][N];
vector<pair<int,long long> >g[M];//g[i].size<=d<=20 

void solve(){
	memset(f,0x3f,sizeof(f));//0x7f too big 0x7f+0x7f more than long long
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){//O(m*len*len)=O(2e8) 
		int len=g[i].size(),u,v;
		for(int j=0;j<len;j++){
			u=g[i][j].first;
			for(int k=j+1;k<len;k++){
				v=g[i][k].first;
				f[u][v]=min(f[u][v],g[i][j].second+g[i][k].second);
			}
		}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			f[j][i]=f[i][j];
	
	for(int k=1;k<=n;k++)//floyd O(n*n*n)=O(1.25e8)
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
	
//	for(int i=1;i<=n;i++,printf("\n"))
//		for(int j=1;j<=n;j++)
//			printf("%lld ",f[i][j]);

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int len,u;long long t;
		scanf("%d",&len);
		for(int j=1;j<=len;j++){
			int u;long long t;
			scanf("%d%lld",&u,&t);
			g[u].push_back({i,t});
		}
	}
	solve();
	int x,y,lenx,leny,u,v;long long ans;
	while(q--){
		scanf("%d%d",&x,&y);
		ans=1e18;
		lenx=g[x].size(),leny=g[y].size();
		for(int i=0;i<lenx;i++){
			for(int j=0;j<leny;j++){
				u=g[x][i].first,v=g[y][j].first;
				ans=min(ans,g[x][i].second+f[u][v]+g[y][j].second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}