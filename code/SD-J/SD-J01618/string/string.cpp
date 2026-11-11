#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	pair<int,char>a[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].fi>>a[i].se;
	}
	int l=1,r=n,x;
	while(l<r)
	{
		x=min(a[l].fi,a[r].fi);
		if(a[l].se!=a[r].se)
		{
			sum+=x;
		}
		if(a[l].fi==x){
			a[r].fi-=x;
			l++;
		}
		else 
		{
			a[l].fi-=x;
			r--;
		}
	}
	cout<<sum;
	return 0;
}
