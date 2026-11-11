#include<bits/stdc++.h>
using namespace std;
long long l,t,n,m,a[2000009];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>l>>t;
	for(int i=1;i<=t;i++)
	{
		long long ok=0;
		cin>>n>>m;
		for(int j=1;j<=n;j++)
		{
	    	cin>>a[j];
			if(j>2&&a[j]-a[j-1]!=a[j-1]-a[j-2])ok=1;
		}
		if(ok==0&&2*(a[n]-a[n-1])<=m&&n-m/(a[n]-a[n-1])*2+1>0)cout<<n-m/(a[n]-a[n-1])*2+1<<endl;
		else cout<<0<<endl;
	}
}
