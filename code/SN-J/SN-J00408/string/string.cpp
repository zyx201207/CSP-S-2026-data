#include<bits/stdc++.h>
using ll=long long;
using namespace std;

const int maxn=2e5+10;

ll n,tot,idd;

struct node{
	ll total;
	char val;
}a[maxn];

struct edge{
	ll l,r;
	char ch;
}z[maxn];

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].total>>a[i].val;
	for(int i=1;i<=n;i++)tot+=a[i].total;
	ll midd=(tot+1)/2;
	ll tooo=0,mid=0;
	for(int i=1;i<=n;i++)
	{
		z[++idd].l=tooo+1;
		tooo+=a[i].total;
		z[idd].r=tooo;
		z[idd].ch=a[i].val;
		if(tooo>=midd&&tooo-a[i].total+1<=midd&&tot!=midd)
		{
			mid=i;
			z[++idd].l=midd+1,z[idd].r=z[idd-1].r;
			z[idd-1].r=midd;
			z[idd].ch=z[idd-1].ch=a[i].val;
		}
	}
//	for(int i=1;i<=idd;i++)cout<<z[i].l<<" "<<z[i].r<<endl; 
	ll lid=1,rid=tot,lidid=1,ridid=idd,ans=0;
	while(lid<rid&&lidid<ridid)
	{
		if(z[lidid].ch!=z[ridid].ch)
		{
			if(z[lidid].r-lid+1>rid-z[ridid].l+1)
			{
				ans+=rid-z[ridid].l+1;
				lid=lid+rid-z[ridid].l+1;
				rid=z[ridid].l-1;
				ridid--;
			}
			else
			{
				ans+=z[lidid].r-lid+1;
				rid=rid-z[lidid].r+lid-1;
				lid=z[lidid].r+1;
				lidid++;
			}
		}
		else 
		{
			if(z[lidid].r-lid+1>rid-z[ridid].l+1)
			{
				lid=lid+rid-z[ridid].l+1;
				rid=z[ridid-1].r;
				ridid--;
			}
			else
			{
				rid=rid-z[lidid].r+lid-1;
				lid=z[lidid].r+1;
				lidid++;
			}
		}
//		cout<<lid<<" "<<rid<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
