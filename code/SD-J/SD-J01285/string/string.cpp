#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
struct Node{
	long long num;
	char w;
};
bool cmp(Node a,Node b)
{
	return a.num>b.num;
}
Node w[27];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		w[b[i]-'a'].num+=a[i];
	}
	if(n%2!=0)
	{
		for(int i=0;i<n/2+1;i++)
		{
			if(b[i]!=b[n-i-1])
			{
				if(w[b[i]-'a'].num>w[b[n-i-1]-'a'].num)
				{
					ans+=a[i];
				}
				else
				{
					ans+=a[n-i-1];
				}
			}
			/*
			else
			{
				ans+=abs(a[i]-a[n-i-1]);
				if(a[i]>a[n-i-1])
				{
					a[n-i-2]=a[i]-a[n-i-1];
				}
				else
				{
					a[i+1]=a[i]-a[n-i-1];
				} 
			} 
			*/
		}
	}
	
	else
	{
		for(int i=0;i<n/2;i++)
		{
			
			if(b[i]!=b[n-i-1])
			{
				if(w[b[i]-'a'].num>=w[b[n-i-1]-'a'].num)
				{
					ans+=a[i];
				}
				else
				{
					ans+=a[n-i-1];
				}
			}
			/*
			else
			{
				ans+=abs(a[i]-a[n-i-1]);
				if(a[i]>a[n-i-1])
				{
					a[n-i-2]=a[i]-a[n-i-1];
				}
				else
				{
					a[i+1]=a[i]-a[n-i-1];
				} 
			} 
			*/
		}
	}
	cout<<ans;
	return 0;
}

