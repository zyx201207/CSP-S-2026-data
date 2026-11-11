#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
pair<ll,char> a[N];
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	int l=1,r=n;
	while(r-l>=1)
	{
		if(a[l].second==a[r].second)
		{
			if(a[l].first<a[r].first)
			{
				a[r].first-=a[l].first;
				l++;
			}
			else if(a[l].first>a[r].first)
			{
				a[l].first-=a[r].first;
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].first<a[r].first)
			{
				a[r].first-=a[l].first;
				ans+=a[l].first;
				l++;
			}
			else if(a[l].first>a[r].first)
			{
				a[l].first-=a[r].first;
				ans+=a[r].first;
				r--;
			}
			else
			{
				ans+=a[l].first;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}