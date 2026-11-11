#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,a[2000001],p[2000001],sum[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--){
		int ans=0;
		bool f=0;
		scanf("%lld %lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<n;i++){
			p[i]=a[i+1]-a[i];
			sum[i]+=p[i];
		}
		for(int i=1;i+1<n;i++)
			if(p[i]!=p[i+1])
				f=1;
		if(!f){
			ans=(n-p[1])/2;
			printf("%d\n",ans);
			continue;
		}
		if(n<=50000)
			for(int i=1;i<n;i++)
				for(int j=1;j<=m;j++)
					if(a[i]+j>=a[i+1] && a[i+1]+m==a[n])
						ans++;
		printf("%d\n",ans);
	}
	return 0;
}

