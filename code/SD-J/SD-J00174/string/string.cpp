#include<bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define IOS ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);

using namespace std;

struct ch
{
	ll num;
	char c;
}a[MAXN];

ll ans=0,n;

void deal(ll l,ll r)
{
	if(l==r||((n%2==0)&&(l-1==r)))
	{
		cout<<ans;
		return ;
	}
	
	if(a[l].c==a[r].c)
	{
		if(a[l].num>a[r].num)
		{	
			a[l].num-=a[r].num;
			deal(l,r-1);
		}
		else if(a[r].num>a[l].num)
		{
			a[r].num-=a[l].num;
			deal(l+1,r);
		}
		else if(a[l].num==a[r].num)
		{
			deal(l+1,r-1);
		}
	}
	else
	{
		if(a[l].num>a[r].num)
		{
			ans+=a[r].num;
			a[l].num-=a[r].num;
			deal(l,r-1);
		}
		else if(a[r].num>a[l].num)
		{
			ans+=a[l].num;
			a[r].num-=a[l].num;
			deal(l+1,r);
		}
		else if(a[l].num==a[r].num)
		{
			ans+=a[r].num;
			deal(l+1,r-1);
		}
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	IOS
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
	}
		
	deal(1,n);
		
	return 0;
}
