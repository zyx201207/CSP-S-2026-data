#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100],b,c[100],nu=0,d[100],i;
	cin>>n>>b;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	for(i=0;i<n;i++)
	{
		if(i>=n-1)
		{
			return 0;
		}
		c[i]=a[i]-a[i+1];
		
		d[i]=a[i];	
		cout<<c[i]<<" ";
    }   
	for(i=0;i<n;i++)
	{    
	    if(c[i]==0)
			{
				nu++;
			}
    }
	cout<<nu; 
	if(b==nu+1)
		{
			cout<<d[i]<<" ";
			return 0;
		}
}
