#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		long long x[n];
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		int dp[n]={0};
		for(int j=0;j<n-3;j++){
			if(x[j]+d>=x[j+1]&&x[j]+d<x[j+3]&&x[j+2]+d>=x[j+3]&&x[j+1]+d>=x[j+2]&&(x[j+2]<=x[j]+d||x[j+1]+d>=x[j+3]))dp[j]++;
			if(x[j]+d<x[j+1])dp[j]--;
		}
		int ans=0,num=0;
		for(int j=0;j<n-3;j++){
			/*if(dp[j]==1&&j==n-4){
				num++;
				int pl=0;
				for(int k=1;k<=num;k++){
					pl+=k;
				}
				ans+=pl;
			}
			else if(dp[j]==1){
				num++;
			}
			
			else{
				int pl=0;
				for(int k=1;k<=num;k++){
					pl+=k;
				}
				ans+=pl;
			}*/
			if(dp[j]==1)ans++;
		}
		cout<<ans;
	}
}
