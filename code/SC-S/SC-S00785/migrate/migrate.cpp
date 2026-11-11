#include<iostream>
using namespace std;
int op,t,n,way[5010][5010],ans;
long long d,x[2000010],f[5010][5010],c;
bool flag;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> op >> t;
	while(t--){
		flag=1;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			if(i>=2){
				if(i>=3 && c!=x[i]-x[i-1]){
					flag=0;
				}
				c=x[i]-x[i-1];
			}
		}
		if(flag){
			c=d/c;
			if(c==1 || c==0){
				printf("0\n");
			}
			else{
				printf("%d\n",max(0ll+n-2*c+1,0ll));
			}
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				way[i][j]=0;
				f[i][j]=1e9;
			}
			f[i][i]=0;
			way[i][i]=1;
			for(int j=i;j<=n;j++){
				ans+=(way[i][j]==2);
				for(int k=j;k<=n && x[k]-x[j]<=d;k++){
					if(f[i][j]+1==f[i][k]){
						way[i][k]+=way[i][j];
					}
					if(f[i][j]+1<f[i][k]){
						way[i][k]=way[i][j];
						f[i][k]=f[i][j]+1;
					}
				}
				//printf("%d %d	",f[i][j],way[i][j]);
			}
			//printf("\n");
		}
		printf("%d\n",ans);
	}
	return 0;
}