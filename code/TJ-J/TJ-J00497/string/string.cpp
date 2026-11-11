#include<bits/stdc++.h>
#include<cstring>
#include<iostream>
using namespace std;
long long int l=0,k=0,ans=0;
long long int n,a[1000];
string c,w;
int main()
{
	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l=l+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			w=w+c[i];
		}
	}
	int s=0;
	for(int i=1;i<=l;i++)
	{
		if(c[i]==c[i+1])
		{
			s++;
		}
	}
	if(s==c.length())
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(l%2==0)
		{
			k=1;
			for(int j=l;j>=l/2;j--)
			{
				if(w[j]!=w[k])
				{
					w[j]=w[k];
					k++;
					ans++;
				}
			}
		}
		if(l%2!=0)
		{
			k=1;
			for(int j=l;j>=l/2+1;j--)
			{
				if(w[j]!=w[k])
				{
					w[j]=w[k];
					k++;
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//3
//2 a
//2 b
//1 c
