#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[350],f[350][350];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;scanf("%lld%lld",&c,&t);
	while(t--){
		int n,count=0;long long d;
		int cnt[350][350]={0};
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			for(int j=1;j<=n;j++) f[i][j]=4e18;
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d) f[i][j]=1,cnt[i][j]=1;
		}for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(!(k>i&&k<j)) continue;
					if(f[i][k]+f[k][j]==f[i][j]) cnt[i][j]++;
					if(f[i][k]+f[k][j]<f[i][j]) 
						cnt[i][j]=cnt[i][k]*cnt[k][j],f[i][j]=f[i][k]+f[k][j];
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				//printf("%d ",f[i][j]);
				if(cnt[i][j]==2) count++;
			}
		printf("%lld\n",count);
	}fclose(stdin);
	fclose(stdout);
}
