#include<bits/stdc++.h>
#define ll long long
ll a[500005];
ll f[500005];
ll m,n,ans,max=-1,js;
using namespace std;
bool cmp(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		js+=a[i];
	} 
	sort(a+1,a+n+1,cmp);
	int f=0;
	for (int i=1;i<n;i++)
	{
		if (a[i]!=a[i+1])
		{
			f=1;
			break;
		}
	}
	if (f==0)
	{
		cout<<n;
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		int x=a[i]*(n-i+1);
		int c=x-js;
		if (c<=m)
		{
			cout<<n-i+1;
			return 0;
		}
		js-=a[i];
	} 
	cout<<"1"<<endl;
	return 0; 
} 

