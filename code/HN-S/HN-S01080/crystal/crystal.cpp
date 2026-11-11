#include<bits/stdc++.h>
using namespace std;
long long ans,dt,cnt;
int a,b,c,dp[5000005],op[5000005],gs=1,kl;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>dp[i];
	
	} 
	sort(dp+1,dp+a+1);
	for(int i=1;i<=a;i++){
		op[i]=dp[a]-dp[i];
	}
	dt=1;
	for(int i=1;i<a;i++){
		int h=(dp[i+1]-dp[i])*gs;
		//cout<<' '<<dp[i]<<' '<<endl;
		if(ans+h<=b){
			gs++;
			ans+=h;
		}else{
			while(ans+h>b){
				ans=ans-(op[dt]-op[i+1]);
				gs--;
				dt++;
			}	
			ans+=h;
			gs++;
		}
		kl=max(kl,gs);
		//cout<<gs<<' ';
	}
	cout<<kl;
	return 0;
} 
