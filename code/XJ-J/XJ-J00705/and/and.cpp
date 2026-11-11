#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int sum[N],n,m,a[N],ans=-1e9;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=0;
	for(int i=1;i<=n-m;i++)
	{		
		x=a[i];
		for(int l=i;l<=i+m;l++)
		{
			x=x&a[l];
		}
		ans=max(ans,x);

	}
	cout<<ans;
}