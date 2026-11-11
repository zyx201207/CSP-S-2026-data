#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=-1,f=0;
	long long m=0,g=-1,k=0;
	string s;
	cin>>n;
	string a[n];
	int c[n];
	for(int i=0;i<n;i++)
	{
		cin>>c[i]>>a[i];
		m+=c[i];
	}
	string b[m];
	for(int i=0;i<n;i++)
	{
		l++;
		for(int j=1;j<=c[i];j++)
		{
			g++;
			b[g]=a[l];
		}
	}
	for(int i=0;i<m%2+m/2;i++)
	{
		if(b[i]!=b[m-1-i])
		{
			k++;
			b[i]=b[m-1-i];
		}
	}
	cout<<k;
} 

