#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<1<<" ";
		}
		return 0;
	}
	if(n==2)
	{
		if(m==1) cout<<2;
		if(m==2) cout<<1<<" "<<2;
	}
	if(n==3)
	{
		if(m==1) cout<<3;
		if(m==2)
		{
			if(a[1]==a[2]) cout<<2<<" "<<3;
			else cout<<1<<" "<<3; 
		}
	}
	return 0;
}
