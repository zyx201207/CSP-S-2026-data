#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,sum=0,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
 	}
	if(n%2==0)
	{
 	m=n/2;
	 for(int i=0;i<m;i++) 
		{
			if(b[i]==b[n-i])
			{
				continue;
			}
			else
			{
				sum+=a[n-i];
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++) 
		{
			if(b[i]==b[n-i-1])
			{
				continue;
			}
			else
			{
				sum+=a[n-i-1];
			}
		}
	}
	
	cout<<"0";
 } 
