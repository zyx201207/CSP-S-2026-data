#include<bits/stdc++.h>
using namespace std;
long long c,t,a[5010],sum;
pair<long long,long long> dp[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(long long len=1;len<n;len++){
		for(long long i=1;i<=(n-len);i++){
		long long j=i+len;
			if(a[j]-a[i]<=d){
				dp[i][j]={1,1};
				continue;
			}
			if(j==i+1){
				dp[i][j]={1e9+1,0};
			}
			long long mn=1e9,wp=0;
			for(long long k=i+1;k<j;k++){
				long long jb1=dp[i][k].first,ds1=dp[i][k].second;
				long long jb2=dp[k][j].first,ds2=dp[k][j].second;
				if(jb1+jb2<mn){
					mn=jb1+jb2;
					wp=ds1*ds2;
				}else if(jb1+jb2==mn){
					wp+=ds1*ds2;
				}
			}
			if(wp==2){
				sum++;
			}
			dp[i][j]={mn,wp};
		
	}
		}
		
		cout<<sum<<'\n';
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/