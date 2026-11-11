#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int x,t;
	cin>>x>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d,ans=0;
		cin>>n>>d;
		int a[n+10];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-3;i++)
		{
			if(a[i+2]-a[i]<=d and a[i+3]-a[i+1]<=d and a[i+3]-a[i]>d)
				ans++;
		}
		cout<<ans<<endl;
	}
}
