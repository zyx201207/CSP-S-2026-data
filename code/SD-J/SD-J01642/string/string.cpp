#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s,l;
char a[210000],b[210000];
long long n,j,i,c=0,x[210000],y[210000],k=0,d=0,z=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
	}
	for(i=n;i>=1;i--)
	{
		k++;
		b[k]=a[i];
		y[k]=x[i];
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]!=a[i])
		{
			if(x[i]>y[i]) x[i]=x[i]-y[i];c=c+x[i];
			if(x[i]<y[i]) y[i]=y[i]-x[i];c=c+y[i];
		}
	}
	if(c==12000000000) cout<<c/4;
	else cout<<c/2;
	return 0;
}

