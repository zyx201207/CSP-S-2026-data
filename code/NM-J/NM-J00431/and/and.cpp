#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,m,nums[200005];
bool comp(int a,int b){
	return a<b;
}
int main(){
	freopen("and2.in","r",stdin);
	freopen("and2.out","w",stdout);
    cin>>n>>m;
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
    for(long long i=1;i<=n;i++){
        cin>>nums[i];
    }
    dp[1][1]=nums[1];
    for(long long i=2;i<=n;i++){
		dp[i][1]=max(dp[i-1][1],nums[i]);
	}
	for(long long j=2;j<=m;j++){
		dp[j][j]=dp[j-1][j-1]&nums[j];
	}
	//int candidate=0;
	//int can2=0;
    for(long long i=2;i<=n;i++){
        for(long long j=2;j<=m;j++){
            if(i<=j){
				continue;
			}
			else{
				if(nums[i]>=dp[i-1][j-1]){
				    long long a=nums[i]&dp[i-1][j-1];
				    dp[i][j]=max(a,dp[i-1][j]);
				    /*dp[i][j]=max(dp[i][j],min(candidate,can2)&max(candidate,can2));
				    if(candidate!=dp[i-1][j-1]){
						can2=max(can2,candidate);
					}
				    candidate=max(candidate,nums[i]);*/
				}
				else{
					long long a=dp[i-1][j-1]&nums[i];
					dp[i][j]=max(a,dp[i-1][j]);
					/*dp[i][j]=max(dp[i][j],min(candidate,can2)&max(candidate,can2));
					if(candidate!=dp[i-1][j-1]){
						can2=max(can2,candidate);
					}
					candidate=max(candidate,nums[i]);*/
				}
			}
        }
    }
    sort(nums+1,nums+n+1,comp);
    int ans2=nums[n-m+1];
    for(long long i=n-m+2;i<=n;i++){
		ans2=ans2&nums[i];
	}
	if(ans2>dp[n][m]){
		cout<<ans2<<endl;
	}
	else{
		cout<<dp[n][m]<<endl;
	}
    return 0;
}
