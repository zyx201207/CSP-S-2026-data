#include<iostream>
#include<fstream>
#include<algorithm>
#include<string> 
using namespace std;
long long n,m,a[500005],ans=1; 
long long dp[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+1+n);
	}
	
	dp[1]=1;
	long long s=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			s+=a[i]-a[j];
			if(s>m){
				dp[i]=i-j;
				break;
			}
		}
		if(s<=m){
			dp[i]=i;
		}
		ans=max(ans,dp[i]);
		s=0;
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
