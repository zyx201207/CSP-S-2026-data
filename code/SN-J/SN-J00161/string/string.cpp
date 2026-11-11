#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1000],b=1,sum=0;
	char c[1000],x[1000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			x[b]=c[i];
			b++;
		}
	} 
	for(int i=1;i<=b/2;i++)
	{
		if(x[i]!=x[b-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
 } 
