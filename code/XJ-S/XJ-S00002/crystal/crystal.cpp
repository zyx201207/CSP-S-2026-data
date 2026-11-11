#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[n];
	cin>>n>>m>>a[n];
	if(a[n]%3==0)
	{
		cout<<3;
	}
	else
	{
		cout<<n;
	}
	return 0;
}
