#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,k=0,m=0;
	long long a[99999];
	char b[99999];
	char c[99999];
	char x[99999];
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<a[i]; j++)
		{
			x[m]=c[i];
			m++;
		}
	}
	for(int i=m-1; i>0; i--)
	{
		b[s]=x[i];
		s++;
	}
	for(int i=0; i<m/2; i++)
	{                
		if(b[i]!=x[i])  
		{                     
			k++;
		}	
	}
	cout<<k;
	return 0;
}      
   

   
        