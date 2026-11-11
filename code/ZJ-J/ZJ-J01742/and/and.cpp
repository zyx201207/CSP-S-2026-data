#include<bits/stdc++.h>
#define maxn 6005
using namespace std;

bool memjfs;
void read(long long &numx){
	register bool is_minus=0;
	register char xxx=getchar();
	numx=0;

	for(;xxx<'0'||xxx>'9';xxx=getchar()){
		if(xxx=='-'){
			is_minus=1;
		}
	}

	for(;xxx>='0'&&xxx<='9';xxx=getchar()){
		numx=(numx<<3)+(numx<<1)+(xxx^48);
	}

	if(is_minus){
		numx=-numx;
	}
}
long long dp[maxn][maxn];
long long a[maxn];
long long n,m,maxtotal;
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	read(n);read(m);
	
	for(long long i=1;i<=n;i++){
		read(a[i]);
	}
	
	for(long long i=1;i<=n;i++){
		maxtotal=max(maxtotal,a[i]);
		dp[i][1]=maxtotal;
	}
	
	if(m==1){
		printf("%lld",maxtotal);
		return 0;
	}
	
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=min(i,m);j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]&a[i],dp[i-1][j]));
		}
	}

	printf("%lld",dp[n][m]);
	return 0;
}
