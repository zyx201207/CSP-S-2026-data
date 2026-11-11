#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<iostream> 
using namespace std;
long long int f[300000]={},v[300000]={};
int num(int a)
{
	int ber[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1.04858e+006,2.09715e+006,4.1943e+006,8.38861e+006,1.67772e+007,3.35544e+007,6.71089e+007,1.34218e+008,2.68435e+008,5.36871e+008,1.07374e+009};
	for(int i=1;i<=30;i++)
	{
		if(a==ber[i])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		if(num(v[i]))
		{
			v[i]=0;
		}
	//	f[i]=v[i];
	}
	f[0]=pow(2,31)-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			f[j]=max(f[j],f[j-1]&v[i]);
 
		}
	}
	cout<<f[m]; 
	return 0;
} 
