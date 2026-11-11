#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
long long cnt=1,d=0;
char b[100005],c[10000000000];
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		d=d+a[i];	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			c[cnt]=b[i];
			cnt++;
		}
	} 
	int he=d/2,son=0;
	for(int i=1;i<=he;i++)
	{
		if(c[i]!=c[cnt-i])
		{
			son++;
		}
	}
	cout<<son;
	return 0;
}
