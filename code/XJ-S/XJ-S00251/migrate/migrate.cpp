#include<bits/stdc++.h>
using namespace std;
long long n,t,a[5005],limit,ans,ls;
bool check(int x,int y)
{
	if(a[y]-a[x]>0&&a[y]-a[x]<=t) return true;
	if(a[y]-a[x]<0&&a[y]-a[x]>=t) return true;
	return false;
}
void lit(int s,int e,int step)
{
	if(step>limit)
	{
		return ;
	}
	if(s==e)
	{
		ls++;
	}
	for(int i=1;i<=e-1;i++)
	{
		if(!check(s,s+i))
		{
			break;
		}
		lit(s+i,e,step+1);
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i,j,T,c;
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>t;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(i=1;i<=n-3;i++)
		{
			for(j=i+3;j<=n;j++)
			{
				if((j-i+1)%t==0)
				{
					limit=(j-i+1)/t;
				}else
				{
					limit=(j-i+1)/t+1;
				}
				lit(i,j,0);
				if(ls==2) ans++;
				ls=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
