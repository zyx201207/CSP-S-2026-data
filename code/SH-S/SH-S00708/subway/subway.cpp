#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[500005],k,a,t,cnt[500005],x,y;
pair<int,long long>h[500005][21];
long long f[505][505],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&a,&t);
			h[a][++cnt[a]]={i,t};
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				f[h[i][j].first][h[i][k].first]=min(f[h[i][j].first][h[i][k].first],h[i][j].second+h[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ans=inf;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,w[x]+h[x][i].second+f[h[x][i].first][h[y][j].first]+h[y][j].second+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
