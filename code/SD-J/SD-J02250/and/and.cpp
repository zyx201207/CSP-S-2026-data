#include<bits/stdc++.h>
using namespace std;
long long ddd(long long a,long long b){
	bool e[11]={0},j[11]={0};
	int o=0,m=0;
	while(a>0){
		if(a%2==1)
		{e[o]=1;
			a/=2;
		}else{
			e[o]=0;
			a/=2;
		}o++;}
		while(b>0){
	if(b%2==1)
		{
			j[m]=1;
			b/=2;
		}else{
			j[m]=0;
			b/=2;
		}	m++;
		}
	bool g[11]={0}; 
	for(int i=0;i<11;i++)
	{
		if(e[i]==j[i]&&e[i]!=0&&j[i]!=0)
		{
			g[i]=1;
			}
			}
	long long c=0;
	for(int i=0;i<11;i++)
	{
		if(g[i]==1) 
		{	long long v=1;
			for(int z=0;z<i;z++)
			{
				v*=2;
			}
			c+=v;
			cout<<c<<" ";
		}
	}
	return c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n;
	long long a[200000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	 } 
	 long long dp[200000];
	for(int i=1;i<=n;i++)
	{
	for(int j=m;j>0;j--)
	{
	dp[i]=dp[i-1];
	if(j>=1)
	dp[i]=max(dp[i],ddd(dp[i-1],a[i]));
	}}
	cout<<dp[n];
	return 0;
} 
