#include<bits/stdc++.h>
using namespace std;
long long int a,i,k,j,m,n,v,s;
char b[1000000],h;
int main()
{
	cin>>n;
    for(i=1;i<=n;i++)
    {
    	cin>>a>>h;
    	if(a>1000000000)
    	{
    		cout<<0;
    		return 0;
		}
    	for(k=1;k<=a;k++)
    	{
    		m++;
    		b[m]=h;
		}
	}
    if(m%2==0)
    {
    	v=m%2;
    	for(i=1;i<=v;i++)
    	{
    		if(b[i]!=b[m-i])
    		{
    			s++;
			}
		}
		cout<<s;
		return 0;
	}
	if(m%2!=0)
    {
    	v=m-1;
    	v=v/2;
    	for(i=1;i<=v;i++)
    	{
    		if(b[i]!=b[m-i])
    		{
    			s++;
			}
		}
		cout<<s;
		return 0;
	}
} 