#include<bits/stdc++.h>
using namespace std;
int a[110000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,n,m,i,j,s=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])s++;
	}
	for(j=1;j<=m;j++)
	{
		if(s==0)
		{
		cout<<a[n];
		}
	}
	
	
	return 0;
}
