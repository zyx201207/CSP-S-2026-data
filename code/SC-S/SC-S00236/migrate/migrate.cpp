#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int a[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,k,ans=0,an;
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			dp[i]=100000;
		}
		dp[1]=0;
		for(int j=2;j<=n;j++){
			 k=j-1;
			while(a[j]-a[k]<d&&k>0){
				if(a[j]-a[1]<=d) dp[j]=1;
				else{
					dp[j]=min(dp[j],dp[k]+1);
				} 
				k--;
				}
			}
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]-a[j]>d&&dp[i]-dp[j]==2){
					ans++;
				}
			}
		}
			printf("%d\n",ans); 
	}
	return 0;
}