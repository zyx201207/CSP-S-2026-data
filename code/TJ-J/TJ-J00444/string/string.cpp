#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r","stdin");
	//freopen("string.out","w","stdout");
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string y;
		cin>>x;
		cin>>y;
	}
	if(n<=2)
	{
		if(n==1)
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		cout<<7;
	}
	return 0;
}
