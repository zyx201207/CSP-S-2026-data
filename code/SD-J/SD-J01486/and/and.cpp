#include <bits/stdc++.h>
using namespace std;
int f(int a,int b)
{
	int c=a;
	if(b==0)
	{
		return 1;
	}
	while(b!=1)
	{
		a*=c;
		b--;
	}
	return a;
} 
int and0(int n,int m)
{
	int a[1000],b[1000];
	int i=0;
	while(n!=0)
	{
		a[i++]=n%2;
		n/=2;
	}
	int j=0;
	while(m!=0)
	{
		b[j++]=m%2;
		m/=2;
	}
	int c[1000];
for(int k=min(i,j);k>=0;k--)
{
	if(a[k]==1&&b[k]==1)
	{
		c[k]=1;
	}
	else c[k]=0;
}
int d=0,e=min(i,j);
while(e!=0)
{
	e--;
	d+=c[e]*f(2,e);
}
return d;
} 
int main() 
{
	
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int max0=0;
	sort(a,a+n);
	int g=n-m;
	int h=0;
	while(h<n-1)
	{
		//cout<<a[h];
		h=and0(a[g],a[g+1]);
		g++;
	 } 
	cout<<h;
	//cout<<and0(12,15);
	//4 2 3 15 12 12
	return 0;
}
