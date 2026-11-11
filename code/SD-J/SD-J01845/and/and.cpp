#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1[10003],a2[10003];
int f(int n)
{
	int ans;
	while(n)
	{
		ans*=10;
		ans+=n%2;
		n/=2;
	} 
	return ans;
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
		a1[i]=f(a1[i]);
	}
	for(int j=1;j<=n;j++)
	{
		a2[j]=a1[j];
	 } 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a1[i]==a2[j]&&a1[i]==1)
		}
	}	
	cout<<
	return 0;
}
