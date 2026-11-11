#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=1;
struct str{
	long long num,step;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<long long>a(n+2);
	vector<str>dp(n+2);
	for(long long i=0;i<n;i++){
		cin>>a[i];
		dp[i].num=a[i];
		dp[i].step=1;
	}
	dp[0].num=a[0];
	for(long long i=1;i<n;i++){
		for(long long j=0;j<n;j++){
			if((dp[j].num&a[i])>=dp[i].num&&dp[j].step+1<=m&&i!=j){
				dp[i].step=dp[j].step+1;
				dp[i].num=(dp[j].num&a[i]);
			}
		}
		if(dp[i].step==m&&dp[i].num>=maxx){
			maxx=dp[i].num;
		}
	}
	cout<<maxx;
	return 0;
}