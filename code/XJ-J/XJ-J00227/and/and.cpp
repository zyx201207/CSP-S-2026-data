#include<bits/stdc++.h>
using namespace std;
int er(int x,int y)
{
	string x1="",y1="";
	int z=0;
	while(x>0)
	{
		if(x%2==0)
		x1+='0';
		else
		x1+='1'; 
		x/=2;
	}
	while(y>0)
	{
		y1+=char(y%2); 
		y/=2;
	}
	for(int i=min(x1.length(),y1.length()-1);i>0;i--)
	{
		if(x1[i]==y1[i]=='1')
		{
			z=z*10+1;
		}
		else
		{
			z*=10;
		}
	} 
	return z;
} 
int main()
{
	int n,m,a[999];
	frepoen(and.in,"r",stdin)
	freopen(and.out,"w",stdout)
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort (a,a+n);
	int max=0;
	for(int i=n-1;i>=0;i--)
	{
		if(er(a[i],a[i-1])>max)
		{
			max=er(a[i],a[i-1]);
		}
	}
	cout<<max;
	return 0;
}
