#include<bits/stdc++.h>
using namespace std;
int a[200005];	
bool flag[200005];
int n,m,ans=INT_MIN,summ=0;
void dfs(int x)
{
	if(x==m)
	{
		ans=max(ans,summ);
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0)
			{
				int r=summ;
				summ=summ&a[i];
				flag[i]=1;
				dfs(x+1);
				flag[i]=0;
				summ=r;
			}
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
	if(m==1)////////////////////////////////
	{
		int maxx=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			while(a[i]>=0)
			{
				cnt=cnt+a[i]%2;
				a[i]=a[i]/2;
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	else
	{
		
		if(m==n)//////////////////////////////////
		{   
			int sum=0;
			for(int i=1;i<=n;i++)
		    {
			     sum=sum&a[i];
		    }
		cout<<sum;
		return 0;
		}
		else
		{
				if(m==2)///////////////////////////////
				{
					int maxx=INT_MIN;
					for(int i=1;i<=n;i++)
					{
						for(int j=i+1;j<n;j++)
						{
							maxx=max(maxx,a[j]&a[i]);
						}
					}
					cout<<maxx;
					return 0;
				}
				else
				{
					
					if(m==n-1)///////////////
					{
						int sum=00,maxx=INT_MIN;
						for(int j=1;j<=n;j++)
						{
							for(int i=1;i<=n;i++)
							{
								if(i!=j)
								{
									sum=sum&a[i];
								}
							}
							maxx=max(maxx,sum);
						}
						cout<<maxx;
					return 0;
					}
					else
					{
							dfs(1);
							cout<<ans;
							return 0;
					}
					
				}				
			}
		}	return 0;
	}


