#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int cha[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,i,j,x;
	cin>>c>>t;
	long long s=0;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}	
		x=a[i-1]-a[i-2];
		if(x*2>d) cout<<0;
		else
		{
			cout<<(n-4)/2+1;
		}
	}
	return 0;
}
