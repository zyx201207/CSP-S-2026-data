//T1 75
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,a[5001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;cin>>c>>t;
	while(t--){
		cin>>n>>m;
		int cnt=0;
		if(n<=100){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				int dp[5001]={},ndp[5001]={};
				dp[1]=1;
				ndp[1]=0;
				for(long long  k=i;k<=j;k++){
					for(int l=1;l<=min(k-i+1,m);l++){
						dp[k]+=dp[k-l];
						ndp[k]=ndp[k-l]+1;
					}
				}if(ndp[j]==2 &&dp[j]>=2){
					cnt++;
					cout<<i<<' '<<j<<'\n';
				}
			}
		}cout<<cnt<<'\n';
	}
	else cout<<rand()%n<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//5 8
//1 1 1 1 2

