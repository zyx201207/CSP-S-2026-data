#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int cnt[500010];
int n,m;
bool ch(int x,int i)
{
	if(cnt[i]-cnt[x-1]-(x-1)*(a[i]-a[x-1])<=m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
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
		cnt[i]=cnt[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(ch(mid,i))
			{
				r=mid;
//				cout<<1<<" "<<l<<endl;
			}
			else
			{
				l=mid+1;
//				cout<<2<<" "<<l<<endl;
			}
		}
		if(ch(l,i))
		{
			maxx=max(maxx,i-l+1);
		}
//		cout<<maxx<<"\n";
	}
	cout<<maxx;
}

