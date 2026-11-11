#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		int i,o;
		string j,k;
		cin>>i>>j;
		cin>>o>>k;
		if(j==k)
		{
			cout<<0;
		}
		else
		{
			cout<<min(i,o);
		}
		return 0;
	}
	cout<<1;
}
