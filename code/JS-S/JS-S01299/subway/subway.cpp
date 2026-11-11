#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,D=21,INF=2e9+7;
const long long PlusINF=LONG_LONG_MAX-1;
int c,n,m,d,q;
int w[M];
int k[N];

vector<pair<int,int> > h[M];

int g[N][N];
long long dp[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int A,T;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&A,&T);
			h[A].push_back({i,T});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=g[j][i]=INF;
			if(i==j)g[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<h[i].size();x++){
			for(int y=x+1;y<h[i].size();y++){
				g[h[i][y].first][h[i][x].first]=g[h[i][x].first][h[i][y].first]=
				min(g[h[i][x].first][h[i][y].first],h[i][x].second+h[i][y].second);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=g[i][j];
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
			}
		}
	}
	
	int sr,er;
	long long ans;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&sr,&er);
		ans=PlusINF;
		for(int x=0;x<h[sr].size();x++){
			for(int y=0;y<h[er].size();y++){
				ans=min(ans,h[sr][x].second+h[er][y].second+
				dp[h[sr][x].first][h[er][y].first]);
			}
		}
		ans=ans+w[sr]+w[er];
		printf("%lld\n",ans);
	}
	return 0;
}
