#include<bits/stdc++.h>
using namespace std;
long long int i,k=1,j,m,n,a[1000000],b[1000000],c[100000],l,d,o;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(k=1;k<=m;k++)
	{
		for(i=1;i<=n;i++)
	 { 
	      for(j=1;j<=n;j++)
	      {
	      	if(a[j]==k){
	        	b[1000000]={0};
	        	d=1;
	        	b[d++]=a[j];
			}
			else
			b[i]=a[i];
		  }
	 }
	 for(o=1;o<=n;o++)
	 {
	 	if(b[o]==k)
	 	c[k]++;
	 }
	 
	}
	for(k=1;k<=m;k++)
	cout<<b[k]<<" ";
	return 0;
} 