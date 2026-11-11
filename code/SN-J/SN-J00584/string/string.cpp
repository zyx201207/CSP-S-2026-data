#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[200000];
	string d;
	int n,jsq=0,b,c,jm=0,e=0;
	long long i[200000];
	cin>>n;
	for(b=1;b<=n;b++)
	{
		cin>>i[b]>>a[b];
	}
	for(b=0;b<n;b++)
	jm+=i[b];
	b=0;
	do
	{
		for(c=1;c<=i[b];c++)
		{
			e++;
		d[e]=a[b];
	}
		b++;	
	}
	while(b!=n);
	for(b=1;b<jm;b++)
	{
	if(d[b]!=d[jm-b])
	jsq++; 
	}
	cout<<jsq;
	return 0;
}
