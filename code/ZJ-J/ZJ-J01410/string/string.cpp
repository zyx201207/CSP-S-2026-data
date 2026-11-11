#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a';
	}
	int l=1,r=n;
	while(l<r)
	{
		if(b[l]==b[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			}
		}
		else if(b[l]!=b[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
