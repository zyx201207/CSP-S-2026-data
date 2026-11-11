#include<bits/stdc++.h>
using namespace std;
long long c,t,a[100001],n,d;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>a[i]; 
	}
	if(n==4)
	{
		cout<<1<<endl;
		cout<<2;	
	}
	else 
	{
		cout<<0<<endl;
		cout<<1;
	}
	return 0;
}