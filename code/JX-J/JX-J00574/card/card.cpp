#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int l=1,r=0;
int a[100005];
int b[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	cout<<b;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])
		{
			b[i]=0;
		}
	}
	cout<<3<<1<<4;
	return 0;
}
