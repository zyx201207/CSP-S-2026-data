#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ei,ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=m;j++)
		{
			ei=a[i] and a[j];
			ma=max(ma,ei);
			
		}
		
	}
	cout<<ma;
	return 0;
}