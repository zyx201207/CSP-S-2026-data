#include<bits/stdc++.h>
using namespace std;
const int N=29;
int c,n,d;
int x[N];
int dp[N][N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ttt;
	cin>>c>>ttt;
	while( ttt-- ){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)dp[i][j][k]=0;
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if( x[j]-x[i]<=d ){
					dp[i][j][1]=1;
				}
				else break;
			}
		}
		for(int k=2;k<=n;k++){
			for(int i=2;i<=n;i++)for(int j=1; (i+j)<=n ; j++){
				//dp[ j ][ i+j ][k];
				for(int v=j;v<=i+j;v++){
					if( x[v]-x[j]<=d )dp[j][i+j][k]+= dp[v][i+j][k-1] ;
					else break;
				}
			}
		}
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dp[i][j][k]){
					//cout<<dp[i][j][k]<<" ";
					if( dp[i][j][k]==2 )ans++;
					break;
				}
			}
		}
		/**/
		cout<<ans<<"\n";
	}
	return 0;
}
