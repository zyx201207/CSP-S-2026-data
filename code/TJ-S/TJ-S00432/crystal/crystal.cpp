#include<bits/stdc++.h>
using namespace std;
const int N=  5e5+10 ;
long long a[N],t[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	t[i]=t[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i;
		long long z=i*a[i]-m-t[i];
		while(l<r)
		{
			int mid=l+r>>1;
			if(z<=mid*a[i]-t[mid])
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(i-l,ans);
	}
	cout<<ans<<'\n';

    return 0;
}

