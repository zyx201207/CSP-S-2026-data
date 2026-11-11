#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,m;
	string b,c;
	cin>>a;
	if(a==1)
	{
		cin>>n>>b;
		cout<<0;
	}
	if(a==2)
	{
		cin>>n>>b;
		cin>>m>>c;
		if(b==c)
		{
			cout<<0;
		}
		else
		{
			cout<<min(n,m);
		}
	}
	return 0;
}
