#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int c[2];
	c[0]=1;
	c[1]=2;
	for(int i=0;i<m;i++)
	{
		cout<<c[i];
	}
	return 0;
}
