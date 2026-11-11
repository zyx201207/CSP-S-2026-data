#include<bits/stdc++.h>
using namespace std;
int xxr(int wzq)
{	
	int zr=0;
	int qx=1;
	for(int i=wzq;i>0;i/=2)
	{
		int xw=0;
		if(i%2==1)
		{
			i--;
			xw=1;
		}
		zr+=xw*qx;
		qx*=10; 
	}
	return zr;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int max=-1;
	int n,m;
	cin>>n>>m;
	int s[n],s1[n];
	for(int i=0;i<=n;i++)
	{
		cin>>s[i];	
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(s[i]>s[j])
			{
				swap(s[i],s[j]);
			}
			if(s[i]==s[j])
			{
				if(s[i]>max)
				{
					max=s[i];
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		int wzq=s[i];
		s1[i]=xxr(wzq);
	}
	/*
	for(int i=0;i<=n;i++)
	{
		cout<<s[i]<<" ";	
	}
	*/
	if(max>-1&&m==2)
	{
		cout<<max;
	}
	else
	{
		cout<<s[n-m];
	}
	return 0;
}
