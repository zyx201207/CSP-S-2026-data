#include <bits/stdc++.h>
using namespace std;
const int N=2e6+47;
int n,d,c,t,a[N],b[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
			if(j==1) b[j]=0;
			else b[j]=a[j]-a[j-1];
		}
		int x=0;
		for(int j=1;j<=n;j++){
			dp[j]=0;
			dp[j+1]=1;
			int s=0;
			for(int k=j+2;k<=n;k++){
				s+=b[k];
				if(b[k]>d) break;
				else if(b[k]<=d){
					if(k==j+2){
						dp[k]=1;
						continue;
					}
					if(s<d) break;
					if(dp[k-1]==1){
						if(b[k]+b[k-1]<=d){
							dp[k]=2;
							x++;
						}
						else dp[k]=1;
					}
					else if(dp[k-1]==2){
						if(b[k]+b[k-1]<=d){
							break;
						}
						else{
							dp[k]=2;
							x++;
						}
					}
				}
			}
		}
		printf("%d\n",x);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
