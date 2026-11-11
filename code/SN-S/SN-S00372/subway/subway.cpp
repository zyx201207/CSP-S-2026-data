//姓名：刘烨 考点：西北工业大学附属中学 学校：西安交通大学附属中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N],a,t,x,y;
int mp[N][N];
struct node{
	int id,t;
};

vector<node>s[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a,&t);
			s[a].push_back({i,t});
		}
	}
	memset(mp,0x3f,sizeof mp);
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=m;i++){
		int len=s[i].size();
		for(int j=0;j<len-1;j++){
			for(int l=j+1;l<len;l++){
				int u=s[i][j].id,v=s[i][l].id;
				mp[u][v]=mp[v][u]=min(mp[u][v],s[i][j].t+s[i][l].t);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][l]+mp[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		int ans=0x3f3f3f3f3f3f3f3f;
		int lenx=s[x].size(),leny=s[y].size();
		for(int j=0;j<lenx;j++){
			for(int l=0;l<leny;l++){
				int u=s[x][j].id,v=s[y][l].id;
				ans=min(ans,mp[u][v]+s[x][j].t+s[y][l].t+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
