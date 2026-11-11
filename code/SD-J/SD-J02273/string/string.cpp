#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],q=1,w,e,r,p;
char b[100010];
string x,y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		w+=a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		if(b[i]!=b[i+1])
		{
			q=0;
		}
	}
	if(q==1)
	{
		cout<<0;
		return 0;
	}
	if(w%2==0)
	{
		for(int i=0;i<n/2;i++)
		{
			for(int j=0;j<a[i];j++)
			{
				x+=b[i];
				r++;
				if(w/2==r)
				{
					r=0;
					p=1;
					break;
				}
			}
			if(p==1)
			{
				p=0;
				break;
			}
		}
		for(int i=n-1;i>=n/2;i--)
		{
			for(int j=0;j<a[i];j++)
			{
				y+=b[i];
				r++;
				if(w/2==r)
				{
					r=0;
					p=1;
					break;
				}
			}
			if(p==1)
			{
				p=0;
				break;
			}
		}
	}
	else
	{
		for(int i=0;i<n/2+1;i++)
		{
			for(int j=0;j<a[i];j++)
			{
				x+=b[i];
				r++;
				if(w/2+1==r)
				{
					r=0;
					p=1;
					break;
				}
			}
			if(p==1)
			{
				p=0;
				break;
			}
		}
		for(int i=n-1;i>=n/2;i--)
		{
			for(int j=0;j<a[i];j++)
			{
				y+=b[i];
				r++;
				if(w/2+1==r)
				{
					r=0;
					p=1;
					break;
				}
			}
			if(p==1)
			{
				p=0;
				break;
			}
		}
	}
	for(int i=0;i<max(x.size(),y.size());i++)
	{
		if(x[i]!=y[i])
		{
			e++;
		}
	}
	cout<<e;
	
	return 0;
}
