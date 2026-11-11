#include<bits/stdc++.h>
using namespace std;

int id,n,m,d,q;
int cnt; 
long long w[500500];
int head[600500];
long long dis[700][700];

struct bbb{
	int to,last;
	long long v;
}a[1000500];

void add( int x,int y,long long v ){
	a[++cnt].to=y;
	a[cnt].v=v;
	a[cnt].last=head[x];
	head[x]=cnt;
}

bool vis[600500];
long long ans;

void dfs( int now,int to,long long dis,int step ){
	if( step>n<<1 ) return;
	if( now==to ){
		ans=min( ans,dis );
		return;
	}
	for( int i=head[now]; i; i=a[i].last ){
		if( vis[a[i].to] ) continue;
		vis[a[i].to]=1;
		dfs( a[i].to,to,dis+a[i].v,step+1 );
		vis[a[i].to]=0;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&id,&n,&m,&d,&q);
	for( int i=1; i<=m; ++i ){
		scanf("%lld",&w[i]);
	}
	if( id<=8 ){
		for( int i=1; i<=m+n; ++i ){
			for( int j=1; j<=m+n; ++j ){
				dis[i][j]=5e15;
			}
		}
		for( int i=1; i<=n; ++i ){
			int k;
			scanf("%d",&k);
			for( int j=1; j<=k; ++j ){
				int y;
				long long t;
				scanf("%d %lld",&y,&t);
				dis[m+i][y]=t;
				dis[y][m+i]=t;
			}
		}
		for( int i=1; i<=m+n; ++i ){
			for( int j=1; j<=m+n; ++j ){
				for( int k=1; k<=m+n; ++k ){
					dis[i][j]=min( dis[i][j],dis[i][k]+dis[k][j] );
				}
			}
		}
		for( int i=1; i<=m+n; ++i ){
			for( int j=1; j<=m+n; ++j ){
				for( int k=1; k<=m+n; ++k ){
					dis[i][j]=min( dis[i][j],dis[i][k]+dis[k][j] );
				}
			}
		}
		while( q-- ){
			int x,y;
			scanf("%d %d",&x,&y);
			printf("%d\n",dis[x][y]+w[x]+w[y]);
		}
		return 0;
	}
	for( int i=1; i<=n; ++i ){
		int k;
		scanf("%d",&k);
		for( int j=1; j<=k; ++j ){
			int y;
			long long t;
			scanf("%d %lld",&y,&t);
			add( m+i,y,t );
			add( y,m+i,t );
		}
	}
	while( q-- ){
		int x,y;
		scanf("%d %d",&x,&y);
		memset( vis,0,sizeof(vis) );
		ans=5e15;
		dfs( x,y,0,0 );
		printf("%d\n",ans+w[x]+w[y]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}