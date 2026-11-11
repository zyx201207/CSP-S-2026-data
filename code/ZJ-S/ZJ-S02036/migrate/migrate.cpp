#include<bits/stdc++.h>
#define N 2000005
#define LL long long
using namespace std;
LL a[N],dp[N][2];
int f[N],cnt[N];
int w[N];//0 weiyi 1  2
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		int n;
		LL m,ans=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		int j=1;
		for(int i=1;i<=n;i++){
			while(j<n&&a[j+1]-a[i]<=m)j++;
			f[i]=j;
		}
		for(int i=1;i<=n;i++){
			int k=i,cnt=0,g=1;
			for(int j=f[i]+1;j<=n;j++){
				int lk=k,lcnt=cnt,lg=g;
				while(f[k]<j){
					lk=k,lcnt=cnt,lg=g;
					if(min(f[f[k]],j)<=f[f[k]-1]&&f[k]>=k+1)cnt+=g;
					if(f[f[k]-1]>=f[f[k]]-1)g=2;
					else g=1;
					if(min(f[f[k]],j)<=f[f[k]-2]&&f[k]>=k)cnt++;
					if(cnt>1)break;
					k=f[k];
					if(f[k]==k&&k<j){
						cnt=0;
						break;
					}
				}
				if(cnt==1)ans++;
				k=lk,cnt=lcnt,g=lg;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
