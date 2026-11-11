#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,l,r,mid;
int a[500005],s[500005];
bool check(int x,int p)
{
	if(a[x]*(x-p+1) - (s[x]-s[p-1]) > m)return false;
	return true;
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
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)//´Ói-n¿ªÊ¼ÊÔÍ¼Ñ°ÕÒ 
	{
		l=i,r=n;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid,i))
			{
				l=mid+1;
				ans=max(ans,mid-i+1);
			}
			else
			{
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return 0;
}//1 3 7 15 24
