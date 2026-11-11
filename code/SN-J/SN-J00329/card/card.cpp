#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("string.in","w",stdin);	
	freopen("string.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<"0";
	}
	return 0;
}
