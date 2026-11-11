#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=330;
int c,t,n;
ll d,x[N],f[N],dp[N][N],ans;
void hand(int s){
	int l=s;
	ll dis=0;
	for(int i=s+1;i<=n;i++){
		dis+=x[i]-x[i-1];
		while(dis>d){
			for(int j=0;j<=n;j++){
				f[j]-=dp[l][j];
			}
			l++;
			dis-=(x[l]-x[l-1]);
		} 
		for(int j=1;j<=n;j++){
			dp[i][j]=f[j-1];
			f[j]+=dp[i][j];
		}
	}
	for(int i=s+1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]!=0){
				if(dp[i][j]==2)ans++;
				break;
			}
		}
	}
//	cout<<s<<":\n";
//	for(int i=1;i<=n;i++){
//		cout<<dp[i][1]<<"\n";
//	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				f[j]=0;
				for(int k=0;k<=n;k++){
					dp[j][k]=0;
				}
			}
			dp[i][0]=1;
			f[0]=1;
			hand(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
