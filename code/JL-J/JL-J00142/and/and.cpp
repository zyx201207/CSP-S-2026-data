#include<bits/stdc++.h>
using namespace std;
int x[100000005];
long long n,k,ans=0;
bool f=false;
void dfs(int sum,int t)
{
	if(t==k)
	{
		if(ans<sum)
		{
			ans=sum;
		}
		f=true;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f==true)
		{
			sum=x[i];
		}
		dfs((sum&x[i+1]),t+1);
	}
}	
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	dfs(x[1],1);
	cout<<ans<<'\n';
	return 0;
}
