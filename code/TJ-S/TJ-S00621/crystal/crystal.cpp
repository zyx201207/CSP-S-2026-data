#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
long long a[N],m,sum[N];
int n; 
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    	sum[i]=sum[i-1]+a[i];
    int ans=0;
	for(int l=1,r=1;l<=n;l++)
	{
		while(r<=n)
		{
			if(1ll*(r-l+1)*a[r]+sum[l-1]-sum[r]<=m)
			{
				r++;
			}
			else break;
		}
		ans=max(r-l,ans);
	}
	cout<<ans;
}
