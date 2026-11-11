#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
一个字符串是回文串，一定是每一段都相同
先和并，再判断 
*/
ll n;
struct node
{
	ll a;
	char c;
}v[200100];
ll find(ll ans)
{
	ll l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(v[mid].a==ans) return mid;
		if(v[mid].a>ans)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return l;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>v[i].a>>v[i].c;
			
	}
	if(n==1)
	{
		cout<<0<<"\n";
		return 0;
	}
	//双指针
	ll gsl,r;
	char c2=' ';
	
	gsl=0;
	r=n;
	ll ans=0;
	//转那个都一样，不对就转 
	for(ll i=1;i<=n;i++)
	{
		if(i>r) break;
		gsl+=v[i].a;
		while(gsl-v[r].a>=0&&i<=r)
		{
			gsl-=v[r].a;
			if(v[i].c!=v[r].c) ans+=v[r].a;
			r--;
		}
		if(gsl!=0)
		{
			v[r].a-=gsl;
			if(v[i].c!=v[r].c) ans+=gsl;
			gsl=0;
		}
//		cout<<ans<<' '<<gsl<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}

