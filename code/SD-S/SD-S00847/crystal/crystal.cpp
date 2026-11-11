#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int M=5e5+10;
int a[M];
int sum[M];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=1;
	int ans=1;
	for(int r=2;r<=n;r++)
	{
		while(((r-l)*a[r])-(sum[r-1]-sum[l-1])>m)
		{
			l++; 
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
