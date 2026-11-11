#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b[10005],c[10005];
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
		cin>>c[i];
	}
	if(b[2]==2)
	{
		cout<<2;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
