#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(1)
	{
		if(l==r)break;
		if(c[l]==c[r])
		{
			if(a[l]==a[r])
			{
				l++;
				if(l==r)break;
				r--;
				if(l==r)break;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
				if(l==r)break;
			}
			else
			{
				a[l]-=a[r];
				r--;
				if(l==r)break;
			}
		}
		else
		{
			if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				if(l==r)break;
				r--;
				if(l==r)break;
			}
			else if(a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
				if(l==r)break;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
				if(l==r)break;
			}
		}
	}
	cout<<ans;
	return 0;
}