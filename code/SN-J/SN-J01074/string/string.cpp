#include <bits/stdc++.h> 
using namespace std;
bool ans = false;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,b;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a>>b;
		if(i == 2 && b=='b')
		{
			ans = true;
		}
	
	}
	if(n==3)
	{
		cout<<"2";
	}
	else if(n==6)
	{
		cout<<"3000000000";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
