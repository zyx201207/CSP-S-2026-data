#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[10000005],b[10000],c[30000];
bool dp[1000][10000];
stack<int> st;
bool u[3600];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(!st.empty())
		{
			st.pop();
		}
	    for(int j=1;j<=m;j++)
	    {
	    	c[j]=0;	
		}
		for(int j=i;j<=m;j++)
		{
			
		}
	}
	
	return 0;
}
