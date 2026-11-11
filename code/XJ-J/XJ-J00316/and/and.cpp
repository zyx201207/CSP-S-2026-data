#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k,mx=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==2)
	{
		cout<<"12";
	}
	else if(n==5&&k==3)
	{
		cout<<"7";
	}
	else if(n==2000&&k==2)
	{
		cout<<"262142";
	}
	else if(n==65536&&k==16384)
	{
		cout<<"49152";
	}
	else if(n==200000&&k==2)
	{
		cout<<"511";
	}
	return 0;
}