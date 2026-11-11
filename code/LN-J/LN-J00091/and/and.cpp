#include<bits/stdc++.h>
#define INF 0x3f3f3f
int ans=-INF;
using namespace std;
const int N=2e5+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	if(m==2)
   {
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>i;j--)
		{
			ans=max(ans,a[i] & a[j]);
		}
	}
   }
   else
   {
	   sort(a+1,a+n+1,greater<int>());
	   for(int i=1;i<=m;i++) ans=max(ans,a[i] & a[i+1]);
   }
	cout<<ans;
	return 0;
}
