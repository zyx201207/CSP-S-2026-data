#include<bits/stdc++.h>
using namespace std;
long long n,b,t,a[1000010],he=0,m=0;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		int g,s;	
		cin>>g>>s;
		for(int j=1;j<=g;j++)
		{
			m++;
			a[m]=s;
		
		}
	}
	b=m/2;
	t=m%2;
	for(int k=1;k<=b;k++)
	{
		if(a[k]!=a[k+b+t])he++;
	}
	cout<<he;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

