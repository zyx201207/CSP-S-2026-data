#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int dp[500005][500005];
int x,y;
int maxx;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=0;
	}
	int cnt=0;
	if(flag) 
	{
		for(int i=1;i<=m;i++)
		{
			cnt+=i;
		} 
		cout<<cnt;
		return 0;
	}
	sort(1+a,1+a+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j-1]+(j-1)*(a[j]-a[j-1])>m) break;
			dp[i][j]=dp[i][j-1]+(j-1)*(a[j]-a[j-1]);
			maxx=max(maxx,j-i+1);
		} 
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	} 
	cout<<maxx;
	return 0;
}
