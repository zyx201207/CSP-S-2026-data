#include<bits/stdc++.h>
using namespace std;
long long n,u1,ans,l=1,r=1;
string u2;
struct node
{
	long long s1;
	string s2;
}a[200005],b[200005],k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>u1>>u2;
		a[i].s1=u1;
		a[i].s2=u2;
		b[n-i+1].s1=u1;
		b[n-i+1].s2=u2;
	}
	l=1,r=1;
	while(true)
	{
		if(r==l&&r==n+1)
			break;
		if(a[l].s1>b[r].s1)
		{
			a[l].s1-=b[r].s1;
			if(a[l].s2!=b[r].s2)
				ans+=b[r].s1;
			++r;
		}
		else if(a[l].s1==b[r].s1)
		{
			if(a[l].s2!=b[r].s2)
				ans+=a[l].s1;
			++r;
			++l;
		}
		else
		{
			b[r].s1-=a[l].s1;
			if(a[l].s2!=b[r].s2)
				ans+=a[l].s1;
			++l;
		}
	}
	cout<<ans/2;
	return 0;
}
