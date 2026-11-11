#include<bits/stdc++.h>
using namespace std;
long long c,t,ans,sum;
long long a[100050];
void dfs(int x,int y,int step,int m)
{
	if(step>ans)return;
	if(x==y)
	{
		if(step==ans)sum++;
		else if(step<ans)
		{
			ans=step;
			sum=1;
		}
		return;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=m)dfs(i,y,step+1,m);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int cnt=0;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cnt=0;
		for(int i=1;i<=n;i++)cin>>a[i];
	    for(int i=1;i<n;i++)
	    {
	    	for(int j=i+1;j<=n;j++)
	    	{
	    		ans=1e9,sum=0;
	    		dfs(i,j,0,k);
	       		if(sum==2)cnt++;
		    }
	    }
	    cout<<cnt<<"\n";
	}
	return 0;
}
