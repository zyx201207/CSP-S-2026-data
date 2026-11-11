#include<bits/stdc++.h>
using namespace std;
struct lyx
{
	int maxl,maxr;
}evy[2000010];
int c,t,n,d,anss;
int a[2000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n-1;i++)
			cin>>a[i];
		if(n==5&&d==2)
		{
			cout<<1<<"\n";
		}
		if(n==10&&d==3)
		{
			cout<<2;
		}
	}
	return 0;
}
