#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],ans,sum,m;
main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=0;
	while(r<=n)//
	{
		r++;
		sum+=a[r];
		while(l<=r&&a[r]*(r-l+1)-sum>m)
		{
			l++;
			sum-=a[l];
		}
		//cout<<l<<" "<<r;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
//没崩


//有点困/jk，不管了不管了，最后一搏
