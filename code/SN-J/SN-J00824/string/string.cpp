#include<bits/stdc++.h>
using namespace std;
int n,f,j;
long long p;
bool aba(char x[200001])
{
	char y[200001];
	for(long long i=0;i<p;i++)
	{
		y[i]=x[p-i-1];
	}
	int q=0;
	for(long long i=0;i<p;i++)
	{
		if(x[i]!=y[i])
		{
			q=1;
		}
	}
	if(q==0)
	{
		return true;
	}
	else return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[200001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long b;
		char c;
		cin>>b>>c;
		for(long long k=0;k<b;k++)
		{
			a[p]=c;
			p++;
		}
	}
	while(!aba(a))
	{
		if(a[j]!=a[p-j-1])
		{
			a[p-j-1]=a[j];
			f++;
			j++;
		}
		else
		{
			j++;
		}
	}
	cout<<f;
	return 0;
}
