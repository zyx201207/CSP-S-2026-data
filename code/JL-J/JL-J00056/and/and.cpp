#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=1e9;
bool cmp(int x,int y)
{
	return x>y;
	}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans&=a[i];
	}
	if(n==m)
	{
	cout<<ans;
	return 0;}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
		}
		if(m==n-1)
		{
		sort(a+1,a+n+1);	
		for(int i=1;i<n;i++)
		ans&=a[i];
		cout<<ans;
	}
	if(m==2)
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<n;i++)
		if(a[i]==a[i+1]){cout<<a[i];return 0;}
		}
	return 0;
	}
