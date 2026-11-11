#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d;
long long a[2000100];
int tong[2000100],bz[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
//	if(c<=10){
		while(t--){
			ans=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			for(int i=1;i<n&&a[n]>a[i]+d;i++){
//				printf("New %d\n",i);
				for(int j=i+1;j<n;j++){
					if(a[j]-a[i]>=(j-i)*d) break;
					if(a[j]<=a[i]+d){
						bz[j]=1;
						if(tong[j]==1) ans--/*,printf("Oh no!\n")*/;
					}
					for(int k=j+1;a[k]<=a[j]+d&&k<=n;k++){
//						printf("%d\n",k);
						if(bz[k]==bz[j]+1){
							if(tong[k]==1) ans--,tong[k]=-1/*,printf("Oh no!\n")*/;
							else if(tong[k]==0) ans++,tong[k]++/*,printf("I'am here!\n")*/;
						}
						else if(bz[k]==0) bz[k]=bz[j]+1;
//						printf("%d %d\n",k,bz[k]);
					}
//					printf("%d %d\n",j,bz[j]);
					bz[j]=0;tong[j]=0;
				}
				bz[n]=0;tong[n]=0;
			}
			printf("%d\n",ans);
		}
//	}
	return 0;
}
