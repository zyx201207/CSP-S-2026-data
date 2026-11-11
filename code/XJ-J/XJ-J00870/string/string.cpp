#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],g,x,w,c;
char b[100000005],z;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	x=1;
	for(int i=1;i<=n;i++)
	{
		cin>>g>>z;
		w+=g;
		for(int j=x;j<=x+g-1;j++)
		{
			b[j]=z;
		}
		x+=g;
	}
	for(int i=1;i<=w/2;i++)
	{
		if(b[i]!=b[w-i+1])
		{
			c++;
		}
	}
	cout<<c;
	return 0;	
}