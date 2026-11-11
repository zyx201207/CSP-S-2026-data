#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N],l,r,ans;
char s[N];
void cnt(ll x,ll y)
{
	if(s[x]!=s[y]) ans+=min(a[x],a[y]);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}l=1;r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			cnt(l,r);
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r])
		{
			cnt(l,r);
			a[r]-=a[l];
			l++;
		}
		else
		{
			cnt(l,r);
			l++;r--;
		}
	}
	cout<<ans;
	return 0;
}

