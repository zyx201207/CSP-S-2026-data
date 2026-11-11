#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e3+10;
int n,m,a[N],dp[N][N];//前i项里面选j个数的最大值 
int maxx[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx[i]=max(a[i],maxx[i-1]);
	}
	dp[1][1]=a[1];
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=maxx[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m]; 
	return 0;
}
