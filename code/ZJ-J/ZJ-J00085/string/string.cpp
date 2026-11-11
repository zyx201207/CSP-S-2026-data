#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2e5+5;
int n,ans;
struct node
{
	int x;
	char ch;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	IOS;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].ch;
	int l=1,r=n;
	while(l<=r)
	{
		int shd=max(a[l].x,a[r].x);
		if(a[l].x==a[r].x)
		{
			if(a[l].ch==a[r].ch) shd=0;
			a[l].x=0;
			a[r].x=0;
		}
		else if(a[l].x>a[r].x)
		{
			while(a[l].x>a[r].x)
			{
				if(a[l].ch==a[r].ch) shd-=a[r].x;
				a[l].x-=a[r].x;
				--r;
			}
			if(a[l].x>0)
			{
				if(a[r].ch==a[l].ch) shd-=a[l].x;
				a[r].x-=a[l].x;
				a[l].x=0;
			}
		}
		else
		{
			while(a[l].x<a[r].x)
			{
				if(a[l].ch==a[r].ch) shd-=a[l].x;
				a[r].x-=a[l].x;
				a[l].x=0;
				++l;
			}
			if(a[r].x>0)
			{
				if(a[r].ch==a[l].ch) shd-=a[r].x;
				a[l].x-=a[r].x;
				a[r].x=0;
			}
		}
		while(a[l].x==0) ++l;
		while(a[r].x==0) --r;
		ans+=shd;
	}
	cout<<ans;
	return 0;
}