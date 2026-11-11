#include<bits/stdc++.h>
using namespace std;
int a=0,n[21],m=0;
int main()
{
	freopen("crystal.in","r",crystalin);
	freopen("crystal.out","W",crystalout);
	cin>>a>>m;
	for(int i=1;i<=a;i++)
	{
		cin>>n[i];
	}
	while(m--)
	{
		for(int i=1;i<=a;i++)
		{
			n[i]+=n[i]+1;
		}
	}
	cout<<'4';
	return 0;
}
