#include<bits/stdc++.h>
using namespace std;

int C;

using i64 = long long ;

const int N = 2e6 + 2 ;
int n;

int dis[N],cnt[N];

i64 a[N];
i64 ans;
i64 d;

int q[N];
int ss,tt;

int main(){
	//
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%d%d",&C,&T);
	while(T--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i);
		for(int S=1;S<=n;S++){
			memset(dis,127,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			q[ss=tt=0]=S;
			dis[S]=0;
			cnt[S]=1;
			while(ss<=tt){
				int u=q[ss++];
//				printf("Visit %d\n",u);
				for(int i=u-1;i&&a[u]-a[i]<=d;i--){
					if(dis[i]>dis[u]+1){
						dis[i]=dis[u]+1;
						cnt[i]=0;
						q[++tt]=i;
					}
					if(dis[i]==dis[u]+1){
						cnt[i]+=cnt[u];
					}
				}
				for(int i=u+1;i<=n&&a[i]-a[u]<=d;i++){
					if(dis[i]>dis[u]+1){
						dis[i]=dis[u]+1;
						cnt[i]=0;
						q[++tt]=i;
					}
					if(dis[i]==dis[u]+1){
						cnt[i]+=cnt[u];
					}
				}
			}
			for(int i=1;i<=n;i++){
//				printf("%d ",cnt[i]);
				if(cnt[i]==2)
					ans++;
			}
//			puts("");
//			system("pause");
//			puts("");
//			printf("\n");
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}

