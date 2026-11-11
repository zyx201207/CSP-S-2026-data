/*
考号：SN-S00463
姓名：魏熙朝
学校：西安铁一中滨河高级中学
*/ 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],ans,sum[maxn];
int check(int k)
{
	//cout<<k<<"\n";
	int l=1,r=k,temp=0,rjq;
	while(r<=n)
	{
		rjq=a[r]*k-(sum[r]-sum[l-1]);
		//if(k==3)cout<<l<<" "<<r<<" "<<rjq<<"\n";
		if(rjq<=m)
		{
			temp=1;
			break;
		}
		l++,r++;
	}
	return temp;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

