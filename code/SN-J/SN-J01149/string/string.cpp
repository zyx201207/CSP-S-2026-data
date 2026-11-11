#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	string a;
	for (long long i=1;i<=n;i++)
	{
		char st;
		long long n1;
		cin>>n1;
		cin>>st;
		for (long long i=0;i<n1;i++)
		{
			a+=st;
		}
	}
	
	bool tr=1;
    for (long long i=0;i<a.length()-1;i++)
    {
    	if (a[i]!=a[i+1])
    	{
    		tr=0;
		}
	}
	if (tr)
	{
		cout<<0;
		return 0;
	}
	if (a.length()%2==0)
	{
		for (long long i=0,j=a.length()-1;i<=a.length()/2-1,j>a.length()/2-1;i++,j--)
	    {
		    if (a[i]!=a[j])
		    {
			    sum++;
		    }                        
	    }
	}
	else
	{
		for (long long i=0,j=a.length();i<=a.length()/2-1,j>a.length()/2+1;i++,j--)
	    {
		    if (a[i]!=a[j])
		    {
			    sum++;
		    }
	    }
	}
	cout<<sum;
	return 0;
} 
