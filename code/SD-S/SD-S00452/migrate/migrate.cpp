#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const long long MAXN=2e6+10;
const long long MAXNN=2e18;
long long minn;
long long c,t;
long long n,d;
long long dp[MAXN];
long long dpv[MAXN];
long long x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long mj=1;mj<=t;mj++){
		cin>>n>>d;
		memset(dp,0,sizeof(dp));
		memset(x,0,sizeof(x));
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		dp[1]=1;
		for(long long i=2;i<=n;i++){
			for(long long j=1;j<=d;j++){
				if((i-j)>0){
					dp[i]+=dp[i-j];
				} 
			}
		}
		if(dp[n]%2==0){
			cout<<dp[n]/2-1<<"\n";
		}else{
			cout<<dp[n]/2<<"\n";
		}
	}
	return 0;
}

