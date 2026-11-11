#include<bits/stdc++.h>
int main()
{
using namespace std;
    freopen("and.in""r"sitin);
    freopen("and.out""w"sitout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		int a;
		cin>>a;
		sum+=a;
	}
	if(sum>100)
	{
		cout<<12;
	}
	if(sum>10000)
	{
		cout<<7;
	}
	if(sum<100)
	{
		cout<<0;
	}
	return 0;
	}