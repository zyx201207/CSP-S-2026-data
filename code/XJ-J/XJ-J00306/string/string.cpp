#include <bits/stdc++.h>
using namespace std;
int n;
int sum;
int a[200005];
char b[200005];
int zans,cnt; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
		if(i!=1&&b[i]==b[i-1])
		{
			zans++;
		}
	} 
	int zd;
	if(sum%2==0)
	{
		zd=sum/2;
	}
	else
	{
		zd=(sum-1)/2;
	}
	while(zd!=0)
	{
		int i=1;
		if(b[i]!=b[n-i+1])
		{
			cnt++;
		}
		zd--;
	}
	if(zans==(n-1))
	{
		cout<<0;
		return 0;
	}
	cout<<cnt;
	return 0;
 } 

