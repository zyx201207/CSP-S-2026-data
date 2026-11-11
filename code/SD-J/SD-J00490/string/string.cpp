#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans=0;
struct node
{
	ll s;
	char c;
}a[200010];
int main()
{
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	ll l=1,r=n;
	while(l<=r)
	{
		if(a[l].s<a[r].s&&a[l].c!=a[r].c)
		{
			ans+=a[l].s;
			a[r].s-=a[l].s;
			l++;
		}
		else if(a[l].c!=a[r].c)
		{
			ans+=a[r].s;
			a[l].s-=a[r].s;
			r--;
		}
		if(a[l].s<a[r].s&&a[l].c==a[r].c)
		{
			a[r].s-=a[l].s;
			l++;
		}
		else if(a[l].c==a[r].c)
		{
			a[l].s-=a[r].s;
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

