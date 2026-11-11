#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if (n==1)
	{
		int a;
		char b;
		cin>>a>>b;
		cout<<0;
	}
	else if (n==2)
	{
		int a1,a2;
		char b1,b2;
		cin>>a1>>b1;
		cin>>a2>>b2;
		if (b1==b2) cout<<0;
	}
}
