#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,d,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d==1||n<=3||n<d*2)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<n-4+1<<endl;
		}
	}
	return 0;
}
