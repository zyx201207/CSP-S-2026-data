#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m=0,n=0,c=0,q=0;
	bool f=true;
	int maxn=-23;
	int max_a=-23;
	int min_i=0;
	cin>>n>>m;
	int a[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c=a[i];
		max_a=max(max_a,c);
		if(a[min_i]>a[i]) min_i=i;
		while(c>=1&&f)
		{
			if(c%2==0) 
			{
				c/=2;
			}
			else
			{
				f=false;
				break;
			}
		}
	}
	if(f)
	{
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<"      ";
		}
		cout<<a[n-m];
		return 0;
	}
	else if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				q=a[i]&a[j];
				maxn=max(maxn,q);
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(m==3)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					q=a[i]&a[j]&a[k];
					maxn=max(maxn,q);
				}	
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(m==1)
	{
		cout<<max_a;
		return 0;
	}
	else if(m==n)
	{
		q=a[0];
		for(int i=1;i<n;i++)
		{
			q=q&a[i];
		}
		cout<<q;
		return 0;
	}
	else if(m==n-1)
	{
		if(min_i==0)
		{
			q=a[1];
			for(int i=2;i<n;i++)
			{
				q=q&a[i];
			}
		}
		else
		{
			q=a[0];
			for(int i=1;i<n;i++)
			{
				if(i==min_i) continue;
				q=q&a[i];
			}
		}	
		cout<<q;
		return 0;
	}
	return 0;
}
