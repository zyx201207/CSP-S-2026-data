#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll n,ans,l,r;
struct ma{
	char s;
	ll k;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].s;
	}
	l=1;
	r=n;
	while(l<=r)
	{
		if(a[l].s==a[r].s)
		{
			if(a[l].k<a[r].k)
			{
				a[r].k-=a[l].k;
				a[l].k=0;
				l++;			
			}
			else if(a[l].k==a[r].k)
			{
				a[l].k=0;
				a[r].k=0;
				l++;
				r--;
			}
			else
			{
				a[l].k-=a[r].k;
				a[r].k=0;
				r--;
			}
		}
		else
		{
			if(a[l].k<a[r].k)
			{
				a[r].k-=a[l].k;
				ans+=a[l].k;
				a[l].k=0;
				l++;		
			}
			else if(a[l].k==a[r].k)
			{
				ans+=a[l].k;
				a[l].k=0;
				a[r].k=0;		
				l++;
				r--;
			}
			else
			{
				a[l].k-=a[r].k;
				ans+=a[r].k;
				a[r].k=0;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
