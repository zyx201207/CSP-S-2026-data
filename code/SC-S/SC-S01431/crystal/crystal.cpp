#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],b[N];
long long n,m,c=1,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++)
	{
		ans=ans+i*b[i];
		if(ans<=m)
		{
			c++;	
		}
	}
	cout<<c;
	return 0;
}