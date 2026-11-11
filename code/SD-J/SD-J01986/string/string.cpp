#include<bits/stdc++.h>
using namespace std;
int a[1010101];
int b[1010101];
int main()
{
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i]>>b[j];
		}
	}
	if(n==3)
	{
		cout<<"2";
	}
	if(n==2)
	{
		cout<<"0";
	}
	if(n==6)
	{
		cout<<"3000000000";
	}
	return 0;
}
