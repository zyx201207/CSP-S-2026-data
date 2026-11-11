//T2 - subway
#include<cstdio>
#include<vector>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
const long long INF = 1e16;
int len[N],s_len[N],a[M],t[M];
int c,n,m,d,q,w[M],vis[M];
long long dis[N][N];
struct Station{
	int line;
	int ind;
};
vector<Station> pt[M];
inline long long minn(long long a,long long b){
	return a<b?a:b;
}
inline int fread(){
	int c,x=0,f=1;
	c=getchar();
	while(c!=45 && (c<48 || c>57)){
		c=getchar();
	}
	if(c==45){
		f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=fread();n=fread();m=fread();d=fread();q=fread();
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		w[i]=fread();
//		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		len[i]=fread();
//		scanf("%d",&len[i]);
		s_len[i]=s_len[i-1]+len[i];
		for(int j=s_len[i-1]+1;j<=s_len[i];j++){
			a[j]=fread();t[j]=fread();
//			scanf("%d%d",&a[j],&t[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=s_len[i-1]+1;j<=s_len[i];j++){
			if(vis[a[j]]>=1){
				vis[a[j]]=2;
			}
			else{
				vis[a[j]]=1;
			}
			pt[a[j]].push_back((Station){i,j});
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[i]==2){
			for(unsigned int j=0;j<pt[i].size();j++){
				int u=pt[i][j].line,pos_u=pt[i][j].ind;
				for(unsigned int k=0;k<pt[i].size();k++){
					if(j==k)continue;
					int v=pt[i][k].line,pos_v=pt[i][k].ind;
					dis[u][v]=minn(dis[u][v],(long long)(t[pos_u]+t[pos_v]));
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int k=1;k<=n;k++){
				if(i==k || j==k)continue;
				dis[i][j]=minn(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		long long ans=INF;
		x=fread();y=fread();
//		scanf("%d%d",&x,&y);
		for(unsigned int i=0;i<pt[x].size();i++){
			int u=pt[x][i].line,pos_u=pt[x][i].ind;
			for(unsigned int j=0;j<pt[y].size();j++){
				int v=pt[y][j].line,pos_v=pt[y][j].ind;
				ans=minn(ans,dis[u][v]+t[pos_u]+t[pos_v]);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
