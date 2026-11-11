#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int N=2e3+5;
long long c,t,n,d,x[N],cnt,total,dp[N][N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dp,0x3f,sizeof dp);
		for(int i=1; i<=n; ++i){
			cin>>x[i];
			for(int j=i-1; j>=1; --j){
				if(x[i]-x[j]<=d)	dp[j][i]=1;
				else	break;
			}
		}
		for(int k=2; k<n; ++k){
			for(int l=1; l<k; ++l){
				for(int r=k+1; r<=n; ++r){
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]);
				}
			} 
		}
		total=0;
		for(int l=1; l<n-1; ++l){
			for(int r=l+2; r<=n; ++r){
				cnt=0;
				for(int k=l+1; k<r; ++k){
					if(dp[l][k]+dp[k][r]==dp[l][r]){
//						cout<<l<<' '<<k<<' '<<r<<'\n';
						++cnt;
					}
				}
				if(cnt==2)	++total;
			} 
		}
		cout<<total<<'\n';
	}
	return 0;
}

