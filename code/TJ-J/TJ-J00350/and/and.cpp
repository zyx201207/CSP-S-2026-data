#include<iostream>
using namespace std;
const int N=2e5+10;
int n,m,s;
int a[N];
int dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(m==s)
		{
			dp[i]=dp[i-1];
		}
		if(s<m)
		{
			dp[i]=max(dp[i-1],dp[i-1]|a[i]);
		}
		if(dp[i]==dp[i-1]|a[i])
		{
			s++;
		}
	}
	cout<<dp[n];
	return 0;
}
