#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
void ab(int x,int sum,int t){
	if(t==m)
	{
		maxx=max(maxx,sum);
	}
	if(x==n+1)
	{
		return ;
	}
	if(sum==0)
	{
		ab(x+1,a[x],t+1);
	}
	else
	{
		ab(x+1,(sum&a[x]),t+1);
	}
	ab(x+1,sum,t);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		ab(1,0,0);
		cout<<maxx;
	}
	else if(m==1)
	{
		cout<<0;
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	else if(m==n-1)
	{
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				if(flag==1)
				{
					maxx=a[j];
					flag=0;
				}
				else
				{
					maxx&=a[j];
				}
			}
		}
		cout<<maxx;
	}
	else if(n==m)
	{
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(flag==1)
			{
				maxx=a[i];
				flag=0;
			}
			else
			{
				maxx&=a[i];
			}
		}
		cout<<maxx;
	}
	else
	{
		int flag=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			cout<<a[1];
		}
		else
		{
			cout<<n-2;
		}
	}
	return 0;
} 
