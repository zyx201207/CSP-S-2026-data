#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
ll arr[2000005];
ll dp[2000005];
int jp[2000005][25];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; scanf("%d%d",&c,&t);
	while(t--){
		memset(dp,0,sizeof dp);
		int n; 
		ll d; scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&arr[i]);
		}	
		for(int i = 1;i <= n;i++){
			jp[i][0]=*upper_bound(arr+1,arr+n+1,arr[i]+d)-1;
			if(jp[i][0]<0){
				if(arr[i]+d>=arr[n])	jp[i][0]=n;
				else	jp[i][0]=i;
			}
		}
		for(int j = 1;j <= 22;j++){
			for(int i = 1;i <= n;i++){
				jp[i][j]=jp[jp[i][j-1]][j-1];
				// cout << jp[i][j] << " \n"[i==n];
			}
		}
		ll ans = 0;
		for(int i = n;i >= 1;i--){
			dp[i]=dp[jp[i][0]];
			int a = jp[i][0];
			int b = (jp[i][0]-1<=i?-1:jp[i][0]-1);
			int c = (jp[i][0]-2<=i?-1:jp[i][0]-2);
			bool f = 1;
			for(int k = 22;k>=0;k--){
				// cout << i << " " << a << " " << b << endl;
				if(a==n&&a!=b){
					f=0;
					break;
				}	
				int A = jp[a][k];
				int B = (b!=-1?jp[b][k]:-1);
				int C = (c!=-1?jp[c][k]:-1);
				if(B==-1){
					f=0;
					break;
				}
				if(A!=B)	a=A,b=B,c=C;
			}
			if(f){
				a=jp[a][0],b=(b!=-1?jp[b][0]:-1),c=(c!=-1?jp[c][0]:-1);
				if(a!=c&&a==b){
					if(a==n){
						dp[i]++;
					}
					else{
						for(int k = 22;k>=0;k--){
							int A = jp[a][k];
							if(A!=n)	a=A,dp[i]+=(1<<k);
						}
						if(jp[a-1][0]!=n)	dp[i]++;
					}
					
				}
			}
			ans+=dp[i];
			
		}
		printf("%lld\n",ans);
	}	
	return 0;
}