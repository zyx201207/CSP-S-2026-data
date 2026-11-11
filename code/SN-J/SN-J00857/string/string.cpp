#include<bits/stdc++.h>
using namespace std;
int n,a[100005],l=1,r,ll=1;
char s[100005];
long long m,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>s[i];
		m+=a[i];
	}
	r=n;
	int rr=1;
	for(int i=1;i<=m/2;i++)
	{
		if(ll>a[l])
		{
			l++;
			ll=1;
		}
		if(rr>a[r])
		{
			r--;
			rr=1;
		}
		if(s[l]!=s[r])
		{
			ans++;
		}
		ll++;
		rr++;
	}
	cout<<ans;
}
