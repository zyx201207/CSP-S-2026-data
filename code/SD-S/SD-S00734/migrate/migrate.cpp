#include<bits/stdc++.h>
using namespace std;
long long n,d,c;
long long a[2000100];
int cnt=0;
void Solve(){
	cnt=0;
	cin >> n >> d;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int k=1;k<=n;k++)
	{
	long long dp[3100];
	memset(dp,0x3f,sizeof dp);
	int c[3100];
	c[k]=1;
	dp[k]=0;
	for(int i=k+1;i<=n;i++)
	{
		for(int j=i-1;a[j]>=a[i]-d&&j>=k;j--)
		{
			if(dp[j]+1<dp[i])
			{
				c[i]=c[j];
				dp[i]=dp[j]+1;
			}
			else if(dp[j]+1==dp[i])
			{
				c[i]+=c[j];
			}
		}if(c[i]==2) cnt++;//cout << i << c[i] << ']';
	}}
	cout << cnt << '\n';
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> c >> T;
	while(T--)
		Solve();
	return 0;
}
