#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],sum[500001],ans=1;
inline int f(int l,int r,int p)
{
	int md=((l+r)>>1);
	//cout<<l<<' '<<r<<' '<<sum[p-1]-sum[md-1]+m-(p-md)*a[p]<<endl;
	if(l==r)
		return l;
	if(sum[p-1]-sum[md-1]+m>=(p-md)*a[p])
		return f(l,md,p);
	else
		return f(md+1,r,p);
	
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=a[1]; 
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		//cout<<i-f(1,i-1,i)+1<<' ';
		ans=max(ans,i-f(1,i-1,i)+1);
		//cout<<ans<<' '; 
	}
	cout<<ans;
    return 0;
}

