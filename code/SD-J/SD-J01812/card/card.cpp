#include <bits/stdc++.h>
using namespace std;
int a[1000],n,m,an=0,b[10000],c[10000],f[10000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{

	   for(int j=i;j<n;j++)
	   {
	   c[j]=a[j];
	   for(int f=0;f<j-1;f++)
	   {
	   		if(c[f]==c[j]&&c[j]!=0)
	   		{
			  an=1;
	   		c[f]=0; 
			}
	   		 cout<<c[j]<<" ";
	   }
	   for(int j=0;j<n;j++)
	   { 
	   b[c[j]]++; 
	   c[j]=0;
	   }
	  cout<<"\n";
	  }}
	  for(int i=1;i<=n;i++)
	  cout<<b[i]<<" "; 
	return 0;
	}
