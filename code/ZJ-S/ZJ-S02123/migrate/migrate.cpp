#include<bits/stdc++.h>
using namespace std;
int n,d,c,c1,t,t1,a[10000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i<=n;i++)
		{
			cin>>a[i];if(t1+a[i]<d)t1+=a[i];
			else t1=0;
		}
		cout<<0;
	}
}
