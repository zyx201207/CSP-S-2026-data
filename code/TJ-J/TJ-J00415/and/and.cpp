#include<bits/stdc++.h>
using namespace std;
long long a2[50];
long long a[200010];
bool qwe[50],na[50];
int main()
{
	freopen("and.in","r",stdin);
	freopen( "and.out" , "w", stdout );
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a2[0]=1;
	for(int i=1;i<=n;i++)
	{
		a2[i]=a2[i-1]*2;
	}
	long long ans=0;
	bool y=0;
	memset(qwe,1,sizeof(qwe));
	for(int i=30;i>=0;i--)
	{
		long long nm=0;
		for(int j=1;j<=n;j++)
		{
			if(y) qwe[j]=na[j];
			na[j]=qwe[j];
			if(na[j])
			{
				na[j]=(a[j]&a2[i]);
				nm+=na[j];
			}
		}
		y=0;
		if(nm>=m)
		{
			ans+=a2[i];
			y=1;
		}
	}
	cout<<ans;
	return 0;
} 
