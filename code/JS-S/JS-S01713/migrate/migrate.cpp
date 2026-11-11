#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10;
int c,T,n,ans,sum[N];
LL d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i){
			memset(sum,0,sizeof sum);
			for(int k=i+1;k<=n && a[k]-a[i]<=d;++k){
				for(int j=k+1;j<=n && a[j]-a[k]<=d;++j){
					++sum[j];
				}
			}
			for(int j=1;j<=n;++j) if(sum[j]==2) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
