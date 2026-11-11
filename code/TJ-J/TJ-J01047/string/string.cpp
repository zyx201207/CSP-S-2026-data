#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001],ans;
char b[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	long long ll=a[1],rl=a[n];
	while(l<r)
	{
		if(ll==rl)
		{
			if(b[l]!=b[r])
			{
				ans+=ll;
			}
			l++;
			r--;
			ll=a[l];
			rl=a[r];
		}
		if(ll<rl)
		{
			if(b[l]!=b[r])
			{
				ans+=ll;
			}
			rl-=ll;
			l++;
			ll=a[l];
		}
		if(ll>rl)
		{
			if(b[l]!=b[r])
			{
				ans+=rl;
			}
			ll-=rl;
			r--;
			rl=a[r];
		}
	}
	cout<<ans;
	return 0;
}
