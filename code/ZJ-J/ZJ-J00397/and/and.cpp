#include <bits/stdc++.h>
using namespace std;
int m,n,ma=-2e9;
int a[200010];
int q[200010][30];
int t[100];
void dfs(int l,int last,int st)
{
	if(l==m+1)
	{
		ma=max(last,ma);
		return ;
	}
	for(int i=st;i<=n;i++)
	{
		if(l==1)
		{
			dfs(l+1,a[i],i+1);
		}
		int sum=0;
		while(last!=0)
		{
			t[++sum]=last%2;
			last/=2;
		}
		for(int j=1;j<=sum;j++)
		{
			if(q[i][j]==1 && t[j]==1)
			{
				int ans=1;
				for(int k=1;k<=j-1;k++)
				{
					ans*=2;
				}
				last+=ans;
			}
		}
		dfs(l+1,last,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int cnt=0;
		int x=a[i];
		while(x!=0)
		{
			q[i][++cnt]=x%2;
			x/=2;
		}
	}
	dfs(1,0,1);
	cout<<ma;
	return 0;
}