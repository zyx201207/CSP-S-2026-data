#include<bits/stdc++.h>
using namespace std;
int n,m,a[201010],sum=0,ans=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1])
		{
			cout<<i-1<<" ";
		}
	}
	cout<<n;
}