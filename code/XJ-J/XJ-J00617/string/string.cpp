#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],i,j,k=0,sum=0,len;
char b[200005],s[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=a[i];j++)
	{
		s[++k]=b[i];
	}
	len=k;
	for(i=1;i<=len/2;i++)
	{
		if(s[i]!=s[len-i])
		sum++;
	}
	cout<<sum;
	return 0;
}