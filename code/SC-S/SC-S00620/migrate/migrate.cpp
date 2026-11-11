#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=5020;
int c,t,n,f[M][M],g[M][M],ans;
long long x[N],d;
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d),ans=0;
		for(int i=0;i<n;i++)scanf("%lld",&x[i]);
		if(n==1){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){
//			printf("%lld ",d/(x[1]-x[0]));
			if(d/(x[1]-x[0])<2)printf("0\n");
			else printf("%lld\n",max(0ll,n-d/(x[1]-x[0])*2+1));
//			if(n==10&&d==31746031746031745){
//				for(int i=0;i<n;i++)printf("%lld ",x[i]);
//				printf("\n");
//			}
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)f[i][j]=0,g[i][j]=0;
				else if(i<j&&x[j]-x[i]<=d)f[i][j]=g[i][j]=1;
				else f[i][j]=1e9,g[i][j]=0;
			}
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<k;i++){
				for(int j=k+1;j<n;j++){
					int w=f[i][k]+f[k][j];
//					if(k==1&&i==0&&j==4)printf("%d\n",w);
//					if(w<=f[i][j]&&i==0&&j==4)printf("%d %d %d\n",i,k,j);
					if(w<f[i][j])f[i][j]=w,g[i][j]=min(3,g[i][k]*g[k][j]);
					else if(f[i][j]==w)g[i][j]=min(3,g[i][k]*g[k][j]+g[i][j]);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				ans+=(g[i][j]==2);
//				printf("%d ",g[i][j]);
			}
//			printf("\n");
		}
		printf("%d\n",ans);
	}
}