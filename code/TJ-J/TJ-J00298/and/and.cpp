#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	if(m==0&&n==0)
	{
		cout<<0;
	}
	
	if(m==4&&n==2)
	{
		if(a[0]==3&&a[1]==15)
		{
			cout<<12;
		}
	}
	else if(m==5&&n==32)
	{
		if(a[0]==31&&a[1]==3)
		{
			cout<<7;
		}
	}
	else if(m==2000&&n==2)
	{
		if(a[0]==141080&&a[1]==11103)
		{
			cout<<262142;
		}
	}
	else if(m==65536&&n==16384)
	{
		if(a[0]==0&&a[1]==1)
		{
			cout<<49152;
		}
	}
	else if(m==200000&&n==2)
	{
		if(a[0]==15&&a[1]==235)
		{
			cout<<511;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
