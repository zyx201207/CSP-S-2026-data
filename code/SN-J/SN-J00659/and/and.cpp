//zbh   °¿ÏèÖĞÑ§    SN-J00659 
#include<bits/stdc++.h>
using namespace std;
int d_2(int a,int b)
{
	int c=a&b;
	cout<<c;
}
int m,n,dp[200005],a[200005],k=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie();
//	for(int i=1;i<=30;i++)
//	{
//		int ans=1;
//		for(int k=1;k<=i;k++) ans=ans*2;
//		cout<<ans<<endl;
//		k=k+ans;
//	}
//	cout<<k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=m;j>=1;j--)
		{
			if(j==m) dp[j]=a[i];
			else
			{
			//cout<<a[i]<<"---"<<dp[i-1]<<"==";
			dp[j]=max(dp[j],dp[j-1]&a[i]);
			//cout<<(dp[j-1]&a[i])<<' ';
			//cout<<dp[j]<<endl;
			}
		}
	}
	cout<<dp[m];
	return 0;
}
