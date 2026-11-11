#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=5010;
int c,t,n;
int f[M],cnt[M];
long long d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	
	if(c<=10){
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			int ans=0;
			for(int l=1;l<=n;l++){
				f[l]=0,cnt[l]=1;
				int lst=l;long long t=a[l]+d;
				for(int r=l+1;r<=n;r++){
					if(a[r]>t){
						lst=r-1;
						t=a[lst]+d;
						if(a[r]>t) break;
					}
					f[r]=f[lst]+1;
					cnt[r]=cnt[lst];
					for(int k=lst-1;k>=l&&f[k]==f[lst];k--){
						if(a[k]+d<a[r]) break;
						cnt[r]+=cnt[k];
						if(cnt[r]>2) break;
					}
					if(cnt[r]==2) ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	if(c==11||c==12){
		while(t--){
			scanf("%d %lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			long long x=a[2]-a[1];
			if(d<(x<<1)){
				printf("0\n");
				continue;
			}
			long long k=d/x;
			long long ans=n*1ll-(k<<1)+1;
			printf("%lld\n",max(0ll,ans));
		}
	}
	
	return 0;
}