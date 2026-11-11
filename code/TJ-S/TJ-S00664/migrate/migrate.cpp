#include<cstdio>
#include<algorithm>
int n,d;
int x[5012];
int c[5012][5012];
int minn[5012][5012];
int abs(int x){
	if(x<0)x=-x;
	return x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,t;
	scanf("%d%d",&C,&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				c[i][j]=0;
				minn[i][j]=n;
				if(abs(x[i]-x[j])<=d){
					c[i][j]=1;
					minn[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=k-1;i>=1&&x[k]-x[i]<=d;i--){
				for(int j=k+1;j<=n&&x[j]-x[k]<=d;j++){
					//printf("%d %d %d\n",i,k,j);
					if(minn[i][j]>=2)c[i][j]++,minn[i][j]=2;
				}
			}
		}
		
		
		/*for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//printf("c[%d][%d]=%d,minn[%d][%d]=%d\n",i,j,c[i][j],i,j,minn[i][j]);
			}
		}*/
		//puts("");
		//puts("");
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(c[i][j]==2)ans++;
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
