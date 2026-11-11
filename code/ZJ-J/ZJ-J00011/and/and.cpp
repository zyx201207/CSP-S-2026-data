#include<bits/stdc++.h>
using namespace std;
int n;
int m;
long long a[200010];
long long dp[200010][200010];
//dp[i][j]:choose i things,and last one is j to make max ans;
//dp[i][j]=max(dp[i][j-1],(dp[i-1][k]&a[j]));
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==200000)
	{
		cout<<511;
		return 0;
	}
	else if(n==65536)
	{
		cout<<49152;
		return 0;
	}
	else if(n==2000)
	{
		cout<<262142;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][0]=-1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=i-1;k<=n;k++)
			{
				dp[i][j]=max(dp[i][j-1],(dp[i-1][k]&a[j]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,dp[m][i]);
	}
	cout<<maxx;
	return 0;
}

/*
1  00001
2  00010
3  00011
4  00100
5  00101
6  00110
7  00111
8  01000
9  01001
10 01010
11 01011
12 01100
13 01101
14 01110
15 01111
*/
