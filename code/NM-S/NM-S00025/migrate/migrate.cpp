#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const long long INF=1e17+10;
int c,t,n;
long long d;
long long x[N];
long long dp[N];
int way[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	//cout<<'1'<<"WKE:WJD";
	while(t--){
		int ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(x[i]-x[j]<=d)
				break;
				memset(dp,INF,sizeof(dp));
				memset(way,0,sizeof(way));
				//cout<<"YES!";
				way[j]=1;
				dp[j]=0;
				for(int r=j;r<=i;r++){
					for(int w=r-1;w>=j;w--){
						if(x[r]-x[w]>d)
						break;
						//cout<<"YUK";
						if(dp[w]+1<dp[r]){
							dp[r]=dp[w]+1;
							way[r]=way[w];
						}
						else if(dp[w]+1==dp[r]){
							way[r]+=way[w];
						}
					}
				}
				if(way[i]==2)
				ans++;
			}
		}
		
		printf("%d\n",ans);
	}
	return 0; 
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
