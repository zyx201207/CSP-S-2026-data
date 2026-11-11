#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
long long ans=INT_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long cnt=a[i];
	    for(int j=i;j<=i+m-1;j++)
	    {
	    	cnt=cnt&a[j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
