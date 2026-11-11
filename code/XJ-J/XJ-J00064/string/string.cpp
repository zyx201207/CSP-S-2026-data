#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	int n,x=2;
	int a[114514];
	string b[114514];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=10000;i++)
	{
		x*=i;
	}
	cout<<x;
	return 0;
 }
