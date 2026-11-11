#include <bits/stdc++.h>
using namespace std;
long long fll,t,n,d,x[2000010],y[2000010],l,r[2000010],fl[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&fll,&t);
	for(long long ii=1;ii<=t;++ii){
		ans=0;
		scanf("%lld %lld",&n,&d);
		for(long long i=1;i<=n;++i) scanf("%lld",&x[i]);
		for(long long i=1;i<=n;++i){
			for(long long j=i;j<=n;++j){
				r[i]=j;
				if(x[j+1]-x[i]>d) break;
			}
			if(r[i]==i&&i<n) r[i]=0;
		}
		for(long long i=1;i<=n;++i){
			for(long long j=i+1;j<=n;++j){
				int flag=1;
				l=0;
				for(long long k=i;k<j;k=r[k]){
					y[++l]=x[k];
					if(!k){
						flag=0;
						break;
					}
				}
				if(!flag) continue;
				y[++l]=j;
				for(int k=2;k<l;++k){
					if(y[k]+1<y[k+1]&&y[k]+1-y[k-1]<=d) --flag;
					if(y[k]-1>y[k-1]&&y[k+1]-y[k]+1<=d) --flag;
					if(y[k]+2<y[k+1]&&y[k]+2-y[k-1]<=d) --flag;
					if(y[k]-2>y[k-1]&&y[k+1]-y[k]+2<=d) --flag;
					if(flag<0) break;
				}
				if(flag) continue;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
