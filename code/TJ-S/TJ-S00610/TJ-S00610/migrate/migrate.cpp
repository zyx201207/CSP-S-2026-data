#include <cstdio>
#include <cassert>
#include <algorithm>
const int N=505;
int n;
long long k;
long long a[N];
int dp[N][N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _,T;
	scanf("%d%d",&_,&T);
	while (T--) {
		scanf("%d%lld",&n,&k);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		std::sort(a+1,a+1+n);
		int ans=0;
		for (int l=1;l<=n;l++) {
			for (int r=l+1;r<=n;r++) {
				int cnt=0;
				bool f=true;
				for (int i=l,pos=a[l];i<=r;i++) {
					if (i==r || a[i+1]-pos>k) {
						if (a[i]-pos>k){f=false;break;}
						cnt++;
						pos=a[i];
					}
				}
				if (!f) continue;
//				printf("%d %d\n",l,r);
				for (int i=l;i<=r;i++) for (int j=0;j<=cnt;j++) dp[i][j]=0;
				for (int j=0;j<=cnt;j++) dp[l][j]=1;
				dp[l][0]=1;
				for (int i=l;i<=r;i++) {
					for (int j=l;j<i;j++) {
						if (a[i]-a[j]<=k) {
							for (int id=1;id<=cnt;id++) {
								dp[i][id]+=dp[j][id-1];
							}
						}
					}
				}
				if (dp[r][cnt]==2) {
//					printf("%d %d\n",l,r);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
