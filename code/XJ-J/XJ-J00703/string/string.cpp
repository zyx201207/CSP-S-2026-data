#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int s;
	char c;
}a[200005];
long long int n,i,l,r,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	for(l=1,r=n;l<r;)
	{
		if(a[l].s>a[r].s)
		{
			a[l].s-=a[r].s;
			if(a[l].c!=a[r].c)
			ans+=a[r].s;
			r--;
		}
		else
		if(a[l].s<a[r].s)
		{
			a[r].s-=a[l].s;
			if(a[l].c!=a[r].c)
			ans+=a[l].s;
			l++;
		}
		else
		if(a[l].s==a[r].s)
		{
			if(a[l].c!=a[r].c)
			ans+=a[l].s;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
