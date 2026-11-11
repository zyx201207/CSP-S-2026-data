#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,r,sizk[505],a[505][20005],id[505][20005],pos[20005][505];
long long w[20005],t[505][20005],dp[205][405][25];
vector<int> v[20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&r);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			pos[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&sizk[i]);
		for(int j=1;j<=sizk[i];j++){
			scanf("%d",&a[i][j]);
			int siz=v[a[i][j]].size();
			scanf("%lld",&t[siz][a[i][j]]);
			v[a[i][j]].push_back(i);
			id[siz][a[i][j]]=j;//a[i][j]在其第siz线路的位置
			pos[a[i][j]][i]=siz;//i线路在a[i][j]所有线路的位置
		}
	}
	for(int q=1;q<=r;q++){
		int s,ed;
		scanf("%d%d",&s,&ed);
		long long ans=1e18;
		int siz;
		for(int i=0;i<=n;i++){
			for(int j=1;j<=m;j++){
				siz=v[j].size();
				for(int k=0;k<siz;k++){
					dp[i][j][k]=1e18;
				}
			}
		}
		siz=v[s].size();
		for(int k=0;k<siz;k++) {
			dp[0][s][k]=w[s]+t[k][s];
		}
		for(int i=0;i<=n;++i){
			for(int kk=1;kk<=n;++kk){
				for(int jj=1;jj<=sizk[kk];jj++){
					int j=a[kk][jj],k=pos[j][kk];
					siz=v[j].size();
					if(k<0) continue;
					for(int mu=jj+1;mu<=sizk[kk];mu++){
						int K=pos[a[kk][mu]][kk];
						dp[i][a[kk][mu]][K]=min(dp[i][a[kk][mu]][K],dp[i][j][k]);
					}
					for(int k2=0;k2<siz;k2++){
						dp[i+1][j][k2]=min(dp[i+1][j][k2],dp[i][j][k]+t[k][j]+t[k2][j]);
					}
					if(j==ed){
						ans=min(ans,dp[i][ed][k]+t[k][ed]+w[ed]);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
