#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,a[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		cout<<j<<" "; 
	}
	return 0;
 } 
