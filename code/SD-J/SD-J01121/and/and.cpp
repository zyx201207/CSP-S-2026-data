#include<bits\stdc++.h>
using namespace std;
long long int a[2000005],ans;
bool f[2000005];
int n,m;
void dfs(int t,long long int sum)
{
	if(m==t)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			if(sum==0)
			{
				sum=a[i];
			}
			else
			{
				sum=sum&a[i];	
			}
			f[i]=true;
			dfs(t+1,sum);
			f[i]==false;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
