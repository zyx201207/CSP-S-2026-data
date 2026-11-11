#include<bits/stdc++.h>
using namespace std;

int x[2000010],ju[2000010],a[2000010],b[2000010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t; 
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			a[i]=-1;
			b[i]=-1;
			cin>>x[i];
			if(i!=1)
			{
				ju[i-1]=x[i]-x[i-1];
			}
		}
	//	for(int i=1;i<n;i++)cout<<ju[i]<<" ";
	//	cout<<endl;
		int num=0;
		for(int i=1;i<n-2;i++)
		{
			if(ju[i]+ju[i+1]<=d&&ju[i+1]+ju[i+2]<=d&&ju[i]+ju[i+1]+ju[i+2]>d)
			{
				a[i]=i-num-1;
			}
			if(ju[i]+ju[i+1]<=d||ju[i]>d)num=i;
		}
		int numm=n;
		for(int i=n-1;i>=3;i--)
		{
			if(ju[i]+ju[i-1]<=d&&ju[i-1]+ju[i-2]<=d&&ju[i]+ju[i-1]+ju[i-2]>d)
			{
				b[i-2]=numm-i-1;
			}
			if(ju[i]+ju[i-1]<=d||ju[i]>d)numm=i;
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
	//		cout<<a[i]<<" "<<b[i]<<endl;
			if(a[i]!=-1&&b[i]!=-1)ans+=(a[i]+1)*(b[i]+1);
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			x[i]=0,ju[i]=0,a[i]=-1,b[i]=-1;
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
