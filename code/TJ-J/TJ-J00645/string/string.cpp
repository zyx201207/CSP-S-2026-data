#include<bits/stdc++.h>
using namespace std;
int n,i=0;
int x;
string x1,x2,x3;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>x1;
		for(int j=1;j<=x;j++)
		{
			x2+=x1[0];
			x3+=x1[0];
		}
	}	
	int n=x2.size();
	int cnt=0;
	for( i=0;i<n/2;i++)
	{
		x3[n-1-i]=x3[i];	
	}
	for( i=0;i<n;i++)
	{
		if(x2[i]!=x3[i])cnt++;	
	}
	cout<<cnt;
	return 0;
}

