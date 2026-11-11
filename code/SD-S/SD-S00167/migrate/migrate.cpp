#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int c,t;
int n,d;
int p[N];
int dis[N][N],cnt[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",p+i);
		sort(p+1,p+n+1);
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			dis[i][i]=0,cnt[i][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&p[j]-p[i]<=d;j++)
				dis[i][j]=1,cnt[i][j]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==k||j==k||i==j)continue;
					if(dis[i][k]+dis[k][j]<dis[i][j])
						dis[i][j]=dis[i][k]+dis[k][j],
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(dis[i][k]+dis[k][j]==dis[i][j])
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(cnt[i][j]==2)ans++;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
